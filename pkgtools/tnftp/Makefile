# $NetBSD: Makefile,v 1.1 2006/07/14 21:41:42 jlam Exp $
#
# This version of tnftp installs into ${PKG_TOOLS_BIN}.
#

.include "../../net/tnftp/Makefile.common"

CATEGORIES=	pkgtools

NO_PKGTOOLS_REQD_CHECK=	yes
PKG_PRESERVE=		yes

PKG_TOOLS_PREFIX=	${PKG_TOOLS_BIN:C|/[^/]?bin$||}

# XXX This breaks for those who set their own LOCALBASE to "/usr" and also
# XXX set PKGMANDIR to be other than "share/man".
# XXX
.if !empty(PKG_TOOLS_PREFIX:M/usr)
PKGMANDIR=		share/man
.endif

.if ${PKG_TOOLS_PREFIX} == ${LOCALBASE}
CONFLICTS+=	kth-krb4-[0-9]*
CONFLICTS+=	lukemftp-[0-9]*
.endif

.include "../../mk/bsd.pkg.mk"

PREFIX:=	${PKG_TOOLS_PREFIX}
