# $NetBSD: Makefile,v 1.1 2025/10/06 00:09:12 thorpej Exp $

UBOOT_TARGET=		d1-nezha
UBOOT_VERSION=		2024.1
UBOOT_CONFIG=		nezha_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

# This is the tip of the d1-wip branch in smaeul's repository as of
# October 5, 2025.
#
# This page explains the situation wrt. Allwinner RISC-V support
# in mainline u-boot.
#
#	https://linux-sunxi.org/Allwinner_Nezha#U-Boot
#
MASTER_SITES=		${MASTER_SITE_GITHUB:=smaeul/}
GITHUB_PROJECT=		u-boot
GITHUB_TAG=		2e89b706f5c956a70c989cd31665f1429e9a0b48
DISTNAME=		u-boot-${UBOOT_TARGET}-${UBOOT_VERSION}
EXTRACT_SUFX=		.tar.gz
#PKGREVISION=		1

DISTINFO_FILE=		${.CURDIR}/../../sysutils/u-boot-d1-nezha/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/u-boot-d1-nezha/patches

post-extract:
	${CP} ${PREFIX}/share/opensbi/sun20i-d1/fw_dynamic.bin ${WRKSRC}

MAKE_ENV+=	OPENSBI=${WRKSRC}/fw_dynamic.bin

.include "../../sysutils/u-boot/u-boot-riscv64.mk"
BUILDLINK_DEPMETHOD.libuuid=	build
.include "../../devel/libuuid/buildlink3.mk"
BUILDLINK_DEPMETHOD.gnutls=	build
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/opensbi-visionfive2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
