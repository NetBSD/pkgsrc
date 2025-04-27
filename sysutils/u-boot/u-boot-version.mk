# $NetBSD: u-boot-version.mk,v 1.7 2025/04/27 21:15:40 gutteridge Exp $

UBOOT_DEFAULT_VERSION=	2018.11

UBOOT_VERSION?=	${UBOOT_DEFAULT_VERSION}

.if ${UBOOT_VERSION} != ${UBOOT_DEFAULT_VERSION}
DISTINFO_FILE?=	${.CURDIR}/../../sysutils/u-boot/distinfo-${UBOOT_VERSION}
# If any consumer of this fragment happens to use buildlink3.mk inclusions
# for other packages it depends upon, and those in turn happen to include
# bsd.prefs.mk (as, for example, gnutls does), then packagers must ensure
# whatever pulls this in is listed before those other dependencies, or
# PATCHDIR will not be set as expected here (and the package will silently
# not apply whatever patches may be intended). Or, alternately, explicitly
# set PATCHDIR to what's intended.
PATCHDIR?=	${.CURDIR}/../../sysutils/u-boot/patches-${UBOOT_VERSION}
.else
PATCHDIR?=	${.CURDIR}/../../sysutils/u-boot/patches
.endif
