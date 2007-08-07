# $NetBSD: Makefile,v 1.2.2.2 2007/08/07 05:00:19 lukem Exp $
#
# This version of tnftp installs into ${PKG_TOOLS_BIN}.
#

.include "../../net/tnftp/Makefile.common"

CATEGORIES=	pkgtools

NO_PKGTOOLS_REQD_CHECK=	yes

CONFLICTS+=	kth-krb4-[0-9]*
CONFLICTS+=	lukemftp-[0-9]*

.include "../../mk/bsd.pkg.mk"
