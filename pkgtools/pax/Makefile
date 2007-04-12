# $NetBSD: Makefile,v 1.14 2007/04/12 14:36:40 joerg Exp $
#
# This version of pax installs into ${PKG_TOOLS_BIN}.
#

.include "../../archivers/pax/Makefile.common"

CATEGORIES=	pkgtools

NO_PKGTOOLS_REQD_CHECK=	yes

PKG_TOOLS_PREFIX=	${PKG_TOOLS_BIN:C|/[^/]?bin$||}

# XXX This breaks for those who set their own LOCALBASE to "/usr" and also
# XXX set PKGMANDIR to be other than "share/man".
# XXX
.if !empty(PKG_TOOLS_PREFIX:M/usr)
PKGMANDIR=		share/man
.endif

.include "../../pkgtools/libnbcompat/inplace.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX:=	${PKG_TOOLS_PREFIX}
