# $NetBSD: Makefile,v 1.6 2002/07/11 14:24:01 abs Exp $
#

PKGNAME=	moz-flash-1.0
PKGREVISION=	2

MAINTAINER=	joda@netbsd.org
COMMENT=	Mozilla open source flash(tm) plugin

PATCHDIR=	${.CURDIR}/../../graphics/libflash/patches
FILESDIR=	${.CURDIR}/../../graphics/libflash/files
DISTINFO_FILE=	${.CURDIR}/../../graphics/libflash/distinfo

DEPENDS+=	libflash>=0.4.10nb1:../../graphics/libflash
DEPENDS+=	mozilla>=0.9.9:../../www/mozilla

USE_X11BASE=	yes

MOZ_PLUGDIR=     ${X11PREFIX}/lib/mozilla/plugins

do-build:
		cd ${WRKSRC}/Plugin && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Plugin && ${INSTALL_PROGRAM} npflash.so ${MOZ_PLUGDIR}

.include "../../graphics/libflash/Makefile.common"
