# $NetBSD: Makefile,v 1.1.1.1 2000/08/28 17:33:50 rh Exp $
#

PKGNAME=	lib${DISTNAME}

DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_LIBTOOL=	yes

do-build:
		cd ${WRKSRC}/Lib && make

do-install:
		cd ${WRKSRC}/Lib && make install

.include	"Makefile.common"
