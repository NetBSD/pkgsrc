# $NetBSD: arm-trusted-firmware-dist.mk,v 1.1 2020/06/30 14:33:14 thorpej Exp $

# When updating, don't forget to also update arm-trusted-firmware-fiptool.
VERSION=	2.3

GITHUB_PROJECT=	arm-trusted-firmware
GITHUB_TAG=	v${VERSION}

DISTNAME=	${GITHUB_PROJECT}-${VERSION}
DISTINFO_FILE?=	${.CURDIR}/../../sysutils/arm-trusted-firmware/distinfo
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ARM-software/}
EXTRACT_SUFX=	.zip
PATCHDIR?=	${.CURDIR}/../../sysutils/arm-trusted-firmware/patches

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/ARM-software/arm-trusted-firmware/
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
