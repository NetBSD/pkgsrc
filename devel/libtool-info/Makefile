# $NetBSD: Makefile,v 1.9 2002/04/17 13:24:24 martti Exp $
#

.include "../libtool/Makefile.common"

PKGNAME=	${PKGPFX:C/-/-info-/}
SVR4_PKGNAME=	ltooi

COMMENT=	Generic shared library support script - info pages

CONFLICTS+=	libtool<1.3.5nb11

TEXINFO_OVERRIDE=	YES

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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
