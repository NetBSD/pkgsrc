# $NetBSD: Makefile,v 1.13 2004/02/05 20:14:06 skrll Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:C/-/-info-/}
SVR4_PKGNAME=	ltooi

COMMENT=	Generic shared library support script - info pages

CONFLICTS+=	libtool<1.3.5nb11

USE_MAKEINFO=	YES
INFO_FILES=	libtool.info

do-build:
	cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
