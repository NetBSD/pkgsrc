# $NetBSD: Makefile,v 1.20 2006/07/14 20:11:10 jlam Exp $
#
# This version of mtree installs into ${PKG_TOOLS_BIN}.
#

.include "Makefile.common"

CATEGORIES=	pkgtools

NO_PKGTOOLS_REQD_CHECK=	# defined
PKG_PRESERVE=		# defined

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
