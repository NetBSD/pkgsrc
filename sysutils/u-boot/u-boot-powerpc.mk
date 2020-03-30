# $NetBSD: u-boot-powerpc.mk,v 1.1 2020/03/30 16:30:54 riastradh Exp $

MAINTAINER=	port-powerpc@NetBSD.org
TOOL_DEPENDS+=	cross-powerpc-none-elf-gcc-[0-9]*:../../cross/powerpc-none-elf-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-powerpc-none-elf/bin/powerpc-none-elf-

.include "u-boot.mk"
.include "../../mk/bsd.pkg.mk"
