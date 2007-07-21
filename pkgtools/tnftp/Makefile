# $NetBSD: Makefile,v 1.2.2.1 2007/07/21 01:19:09 salo Exp $
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
