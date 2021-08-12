# $NetBSD: u-boot-powerpc.mk,v 1.2 2021/08/12 07:30:21 wiz Exp $

MAINTAINER=	port-powerpc@NetBSD.org
TOOL_DEPENDS+=	cross-powerpc-none-elf-gcc-[0-9]*:../../cross/powerpc-none-elf-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-powerpc-none-elf/bin/powerpc-none-elf-

.include "u-boot.mk"
