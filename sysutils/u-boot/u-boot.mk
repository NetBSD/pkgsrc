# $NetBSD: u-boot.mk,v 1.1 2017/08/12 14:23:43 jmcneill Exp $

UBOOT_VERSION?=	2017.07
PKGNAME=	u-boot-${UBOOT_TARGET}-${UBOOT_VERSION}
DISTNAME?=	u-boot-${UBOOT_VERSION}
DISTINFO_FILE?=	${.CURDIR}/../../sysutils/u-boot/distinfo
CATEGORIES=	sysutils
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE?=	https://www.denx.de/wiki/U-Boot
MASTER_SITES?=	ftp://ftp.denx.de/pub/u-boot/

BUILD_DEPENDS+=	dtc>=1.4.2:../../sysutils/dtc

COMMENT=	Das U-Boot, the Universal Boot Loader (${UBOOT_CONFIG})
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_ENV+=	${UBOOT_ENV}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gmake ${UBOOT_CONFIG}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gmake

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/u-boot/${UBOOT_TARGET}
.for bin in ${UBOOT_BIN}
	${INSTALL_DATA} ${WRKSRC}/${bin} \
	    ${DESTDIR}${PREFIX}/share/u-boot/${UBOOT_TARGET}
.endfor

.include "../../mk/bsd.pkg.mk"
