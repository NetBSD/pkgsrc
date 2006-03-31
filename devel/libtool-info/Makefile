# $NetBSD: Makefile,v 1.16 2006/03/31 05:37:08 jlam Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-info-/}
SVR4_PKGNAME=	ltooi

COMMENT=	Generic shared library support script - info pages

CONFLICTS+=	libtool<1.3.5nb11

USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

do-build:
	cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
