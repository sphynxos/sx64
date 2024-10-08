#pragma once

#include <cstdint>
#include <string>
#include <memory>

class Device
{
public:
    Device(const std::string &name = "Unnamed Device", bool readOnly = false, uint64_t baseAddress = 0);
    virtual ~Device() = default;

    virtual void initialize();
    virtual void reset();
    virtual void update();
    virtual uint8_t read(uint64_t address) const;
    virtual void write(uint64_t address, uint8_t data);

    virtual uint64_t getSize() const = 0;

    std::string getName() const;
    std::string getPermissionStr() const;
    bool isEnabled() const;
    void enable();
    void disable();
    uint64_t getBaseAddress() const;
    bool isReadOnly() const;

protected:
    std::string name;
    bool enabled;
    uint64_t baseAddress;

private:
    bool readOnly;
};
