# $NetBSD: Makefile,v 1.20 2012/03/15 11:53:27 obache Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
PKGREVISION=	2
COMMENT=	Machine independent files for Freeciv

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../games/freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--enable-make-data

.include "../../mk/bsd.pkg.mk"
