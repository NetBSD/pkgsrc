# $NetBSD: Makefile,v 1.8 2003/07/13 13:51:44 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-share-/}
PKGREVISION=		1
COMMENT=		Machine independent files for Freeciv

.include "../freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no

.include "../../mk/bsd.pkg.mk"
