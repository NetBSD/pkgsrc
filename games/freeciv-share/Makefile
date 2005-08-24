# $NetBSD: Makefile,v 1.10 2005/08/24 10:36:02 adam Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
COMMENT=	Machine independent files for Freeciv

.include "../freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--enable-make-data

.include "../../mk/bsd.pkg.mk"
