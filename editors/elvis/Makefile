# $NetBSD: Makefile,v 1.2 2004/01/20 22:48:07 recht Exp $
#

.include "./Makefile.common"

PKGNAME=        elvis-2.2.0
PKGREVISION=	1
COMMENT=	Vi clone with regex search, hex editing, HTML and TeX previewing

CONFLICTS+=	elvis-x11[0-9]*

CONFIGURE_ARGS+=	--with-x=no

.include "../../mk/bsd.pkg.mk"
