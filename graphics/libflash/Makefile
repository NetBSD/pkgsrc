# $NetBSD: Makefile,v 1.5 2001/12/03 04:23:00 mycroft Exp $
#

PKGNAME=	lib${DISTNAME}
PKGREVISION=	2

COMMENT=	open source flash(tm) library

DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_LIBTOOL=	yes

do-build:
		cd ${WRKSRC}/Lib && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Lib && ${SETENV} ${MAKE_ENV} ${MAKE} install

.include	"Makefile.common"
