# $NetBSD: Makefile,v 1.4 2001/12/01 00:28:09 hubertf Exp $
#

PKGNAME=	lib${DISTNAME}
PKGREVISION=	1

COMMENT=	open source flash(tm) library

DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_LIBTOOL=	yes

do-build:
		cd ${WRKSRC}/Lib && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
		cd ${WRKSRC}/Lib && ${SETENV} ${MAKE_ENV} ${MAKE} install

.include	"Makefile.common"
