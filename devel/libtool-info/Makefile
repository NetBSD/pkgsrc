# $NetBSD: Makefile,v 1.7 2001/10/18 15:20:11 veego Exp $
#

.include "../libtool/Makefile.common"

PKGNAME=	${PKGPFX:C/-/-info-/}${PKGREV}
SVR4_PKGNAME=	ltooi

COMMENT=	Generic shared library support script - info pages

CONFLICTS+=	libtool<1.3.5nb11

USE_GTEXINFO=	yes

# It seems the info-files distributed with libtool 1.3.5 are broken.
# To test, type "info libtool|" and hold down space. See it stop with a
# ``Cannot find the node "(/usr/pkg/info/libtool.info)Linking executables"''
# error. Simply making sure the info-files get re-done works here.
post-extract:
	${RM} -f ${WRKSRC}/doc/libtool.info*

do-build:
	cd ${WRKSRC}/doc ; ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/doc ; ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
