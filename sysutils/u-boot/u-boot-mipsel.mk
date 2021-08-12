# $NetBSD: u-boot-mipsel.mk,v 1.2 2021/08/12 07:30:21 wiz Exp $

MAINTAINER=	port-mips@NetBSD.org
TOOL_DEPENDS+=	cross-mipsel-none-elf-gcc-[0-9]*:../../cross/mipsel-none-elf-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-mipsel-none-elf/bin/mipsel-none-elf-

.include "u-boot.mk"
