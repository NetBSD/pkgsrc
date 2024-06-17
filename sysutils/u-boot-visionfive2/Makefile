# $NetBSD: Makefile,v 1.1 2024/06/17 20:59:29 skrll Exp $

UBOOT_TARGET=		visionfive2
UBOOT_VERSION=		2024.04
UBOOT_CONFIG=		starfive_visionfive2_defconfig
UBOOT_BIN=		spl/u-boot-spl.bin.normal.out u-boot.itb

post-extract:
	${CP} ${PREFIX}/share/opensbi/visionfive2/fw_dynamic.bin ${WRKSRC}

post-build:
	cp ${WRKSRC}/spl/u-boot-spl.bin ${WRKSRC}/u-boot-spl.bin

MAKE_ENV+=	OPENSBI=${WRKSRC}/fw_dynamic.bin

.include "../../sysutils/opensbi-visionfive2/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-riscv64.mk"
.include "../../mk/bsd.pkg.mk"
