# $NetBSD: Makefile,v 1.12 2003/09/18 16:25:13 jmmv Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${PKGPFX:C/-/-info-/}
SVR4_PKGNAME=	ltooi

COMMENT=	Generic shared library support script - info pages

CONFLICTS+=	libtool<1.3.5nb11

USE_MAKEINFO=	YES
INFO_FILES=	libtool.info

# It seems the info-files distributed with libtool 1.3.5 are broken.
# To test, type "info libtool|" and hold down space. See it stop with a
# ``Cannot find the node "(/usr/pkg/info/libtool.info)Linking executables"''
# error. Simply making sure the info-files get re-done works here.
post-extract:
	${RM} -f ${WRKSRC}/doc/libtool.info*

do-build:
	cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/doc ; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
