# $NetBSD: Makefile,v 1.1.1.1 2001/02/03 05:33:25 hubertf Exp $
#

.include "../libtool/Makefile.common"

PKGNAME=	${DISTNAME:C/-/-info-/}${PKGREV}

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
