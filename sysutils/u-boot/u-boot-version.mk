# $NetBSD: u-boot-version.mk,v 1.5 2021/08/19 07:42:23 wiz Exp $

UBOOT_DEFAULT_VERSION=	2018.11

UBOOT_VERSION?=	${UBOOT_DEFAULT_VERSION}

.if ${UBOOT_VERSION} != ${UBOOT_DEFAULT_VERSION}
DISTINFO_FILE?=	${.CURDIR}/../../sysutils/u-boot/distinfo-${UBOOT_VERSION}
PATCHDIR?=	${.CURDIR}/../../sysutils/u-boot/patches-${UBOOT_VERSION}
.else
PATCHDIR?=	${.CURDIR}/../../sysutils/u-boot/patches
.endif
