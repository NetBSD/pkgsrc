# $NetBSD: Makefile,v 1.3 2001/11/23 14:38:27 agc Exp $
#

PKGNAME=	lib${DISTNAME}

COMMENT=	open source flash(tm) library

DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_LIBTOOL=	yes

do-build:
		cd ${WRKSRC}/Lib && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Lib && ${SETENV} ${MAKE_ENV} ${MAKE} install

.include	"Makefile.common"
