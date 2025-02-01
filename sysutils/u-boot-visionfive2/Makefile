# $NetBSD: Makefile,v 1.3 2025/02/01 02:31:27 gutteridge Exp $

UBOOT_TARGET=		visionfive2
UBOOT_VERSION=		2024.10
UBOOT_CONFIG=		starfive_visionfive2_defconfig
UBOOT_BIN=		spl/u-boot-spl.bin.normal.out u-boot.itb

post-extract:
	${CP} ${PREFIX}/share/opensbi/visionfive2/fw_dynamic.bin ${WRKSRC}

MAKE_ENV+=	OPENSBI=${WRKSRC}/fw_dynamic.bin

.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/opensbi-visionfive2/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-riscv64.mk"
.include "../../mk/bsd.pkg.mk"
