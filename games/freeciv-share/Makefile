# $NetBSD: Makefile,v 1.14 2007/08/16 22:47:19 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
COMMENT=	Machine independent files for Freeciv

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../games/freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--enable-make-data

.include "../../mk/bsd.pkg.mk"
