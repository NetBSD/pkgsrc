# $NetBSD: u-boot-version.mk,v 1.4 2021/03/09 16:49:12 martin Exp $

UBOOT_DEFAULT_VERSION=	2018.11

UBOOT_VERSION?=	${UBOOT_DEFAULT_VERSION}

.if ${UBOOT_VERSION} != ${UBOOT_DEFAULT_VERSION}
DISTINFO_FILE=	${.CURDIR}/../../sysutils/u-boot/distinfo-${UBOOT_VERSION}
PATCHDIR=	${.CURDIR}/../../sysutils/u-boot/patches-${UBOOT_VERSION}
.else
PATCHDIR?=	${.CURDIR}/../../sysutils/u-boot/patches
.endif
