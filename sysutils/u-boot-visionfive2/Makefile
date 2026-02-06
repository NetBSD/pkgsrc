# $NetBSD: Makefile,v 1.7 2026/02/06 10:05:59 wiz Exp $

UBOOT_TARGET=		visionfive2
UBOOT_VERSION=		2024.10
PKGREVISION=		4
UBOOT_CONFIG=		starfive_visionfive2_defconfig
UBOOT_BIN=		spl/u-boot-spl.bin.normal.out u-boot.itb

post-extract:
	${CP} ${PREFIX}/share/opensbi/visionfive2/fw_dynamic.bin ${WRKSRC}

MAKE_ENV+=	OPENSBI=${WRKSRC}/fw_dynamic.bin

PATCHDIR=	${.CURDIR}/patches  # Presently, no patching is intended.
.include "../../sysutils/u-boot/u-boot-riscv64.mk"
BUILDLINK_DEPMETHOD.libuuid=	build
.include "../../devel/libuuid/buildlink3.mk"
BUILDLINK_DEPMETHOD.gnutls=	build
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/opensbi-visionfive2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
