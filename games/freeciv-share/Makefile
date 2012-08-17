# $NetBSD: Makefile,v 1.22 2012/08/17 18:42:43 prlw1 Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
PKGREVISION=	1
COMMENT=	Machine independent files for Freeciv

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../games/freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--enable-make-data

.include "../../mk/bsd.pkg.mk"
