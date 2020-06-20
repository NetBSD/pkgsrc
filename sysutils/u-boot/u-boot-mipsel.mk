# $NetBSD: u-boot-mipsel.mk,v 1.1 2020/06/20 14:38:13 thorpej Exp $

MAINTAINER=	port-mips@NetBSD.org
TOOL_DEPENDS+=	cross-mipsel-none-elf-gcc-[0-9]*:../../cross/mipsel-none-elf-gcc

UBOOT_ENV+=	CROSS_COMPILE=${PREFIX}/cross-mipsel-none-elf/bin/mipsel-none-elf-

.include "u-boot.mk"
.include "../../mk/bsd.pkg.mk"
