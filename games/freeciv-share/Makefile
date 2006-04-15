# $NetBSD: Makefile,v 1.13 2006/04/15 09:30:45 adam Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
COMMENT=	Machine independent files for Freeciv

.include "../../games/freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--enable-make-data

.include "../../mk/bsd.pkg.mk"
