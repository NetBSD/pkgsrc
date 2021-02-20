/*
 * QEMU/mipssim-virtio extension emulation
 *
 * Emulates a very simple machine model similar to the one used by the
 * proprietary MIPS emulator extended by a virtio device. The purpose is to
 * have a better virt platform in anticipation to a readl `virt' platform for
 * MIPS.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Reinoud Zandijk.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "qemu/osdep.h"
#include "qapi/error.h"
#include "qemu-common.h"
#include "cpu.h"
#include "hw/mips/mips.h"
#include "hw/mips/cpudevs.h"
#include "hw/char/serial.h"
#include "hw/isa/isa.h"
#include "net/net.h"
#include "sysemu/sysemu.h"
#include "hw/boards.h"
#include "hw/mips/bios.h"
#include "hw/loader.h"
#include "hw/or-irq.h"
#include "elf.h"
#include "hw/sysbus.h"
#include "hw/qdev-properties.h"
#include "exec/address-spaces.h"
#include "qemu/error-report.h"
#include "sysemu/qtest.h"
#include "sysemu/reset.h"
#include "hw/virtio/virtio-mmio.h"

#define NUM_VIRTIO_TRANSPORTS   32
#define VIRTIO_STRIDE           512

#define DEV_SPACING             0x10000		/* space devices every 64k */
#define ISA_BASE                0x1fd00000
#define	VIRTIO_MMIO_BASE        (ISA_BASE + DEV_SPACING)

extern void mips_mipssim_init(MachineState *machine);

static void
mips_mipssim_virtio_init(MachineState *machine)
{
    DeviceState *virtio_orgate;
    MIPSCPU *cpu;
    CPUMIPSState *env;

    /* initialise parent */
    mips_mipssim_init(machine);

    cpu = MIPS_CPU(qemu_get_cpu(0));
    env = &cpu->env;

    /*
     * TODO: in newer versions, we might need to adjust the cpu clock when its
     * set in mips_mipssim_init()
     */

    /*
     * virtio extention; register 32 virtio devices just after the ISA space
     * at 0x1fd10000 with stride of 512 bytes as per i386s microvm target.
     * register these devices in reverse order (see comments in hw/arm/virt.c)
     */
    virtio_orgate = DEVICE(object_new(TYPE_OR_IRQ));
    object_property_set_int(OBJECT(virtio_orgate),
         "num-lines", NUM_VIRTIO_TRANSPORTS, &error_fatal);
    qdev_realize_and_unref(virtio_orgate, NULL, &error_fatal);

    for (int i = NUM_VIRTIO_TRANSPORTS - 1; i >= 0; i--) {
        sysbus_create_simple("virtio-mmio",
            VIRTIO_MMIO_BASE + i * VIRTIO_STRIDE,
            qdev_get_gpio_in(virtio_orgate, i));
    }
    qdev_connect_gpio_out(DEVICE(virtio_orgate), 0, env->irq[3]);
}

static void mips_mipssim_virtio_machine_init(MachineClass *mc)
{
    mc->desc = "MIPS MIPSsim platform with virtio";
    mc->init = mips_mipssim_virtio_init;
#ifdef TARGET_MIPS64
    mc->default_cpu_type = MIPS_CPU_TYPE_NAME("5Kf");
#else
    mc->default_cpu_type = MIPS_CPU_TYPE_NAME("24Kf");
#endif
    mc->default_ram_id = "mips_mipssim.ram";
}

DEFINE_MACHINE("mipssim-virtio", mips_mipssim_virtio_machine_init)

