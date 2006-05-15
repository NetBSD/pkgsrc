# $NetBSD: Makefile,v 1.3 2006/05/15 16:29:19 joerg Exp $
#

.include "./Makefile.common"

PKGNAME=        elvis-2.2.0
PKGREVISION=	2
COMMENT=	Vi clone with regex search, hex editing, HTML and TeX previewing

CONFLICTS+=	elvis-x11[0-9]*

CONFIGURE_ARGS+=	--with-x=no

.include "../../mk/bsd.pkg.mk"
