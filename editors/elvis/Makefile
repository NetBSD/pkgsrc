# $NetBSD: Makefile,v 1.4 2007/02/22 19:26:25 wiz Exp $
#

.include "./Makefile.common"

PKGNAME=	elvis-2.2.0
PKGREVISION=	2
COMMENT=	Vi clone with regex search, hex editing, HTML and TeX previewing

CONFLICTS+=	elvis-x11[0-9]*

CONFIGURE_ARGS+=	--with-x=no

.include "../../mk/bsd.pkg.mk"
