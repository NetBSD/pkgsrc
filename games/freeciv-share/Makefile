# $NetBSD: Makefile,v 1.9 2004/03/05 12:06:38 adam Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
COMMENT=	Machine independent files for Freeciv

.include "../freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no

.include "../../mk/bsd.pkg.mk"
