# $NetBSD: u-boot-riscv64.mk,v 1.1 2024/05/13 23:07:14 gutteridge Exp $

MAINTAINER=	port-riscv@NetBSD.org
TOOL_DEPENDS+=	cross-riscv64-none-elf-gcc-[0-9]*:../../cross/riscv64-none-elf-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-riscv64-none-elf/bin/riscv64-none-elf-

.include "u-boot.mk"
