# $NetBSD: Makefile,v 1.1 2024/04/29 00:27:03 gutteridge Exp $

UBOOT_TARGET=		beaglebonegreen
UBOOT_CONFIG=		am335x_evm_defconfig
UBOOT_BIN=		u-boot.img
UBOOT_BIN+=		MLO

UBOOT_INSTALLBOOT_PLIST=	installboot.plist

UBOOT_VERSION=		2022.04

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.include "../../security/openssl/buildlink3.mk"
.endif

.include "../../sysutils/u-boot/u-boot-arm.mk"
.include "../../mk/bsd.pkg.mk"
