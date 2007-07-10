# $NetBSD: Makefile,v 1.3 2007/07/10 15:19:18 joerg Exp $
#
# This version of tnftp installs into ${PKG_TOOLS_BIN}.
#

.include "../../net/tnftp/Makefile.common"

PKGREVISION=	1
CATEGORIES=	pkgtools

NO_PKGTOOLS_REQD_CHECK=	yes

CONFLICTS+=	kth-krb4-[0-9]*
CONFLICTS+=	lukemftp-[0-9]*

.include "../../mk/bsd.pkg.mk"
