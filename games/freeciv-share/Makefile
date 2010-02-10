# $NetBSD: Makefile,v 1.17 2010/02/10 19:17:38 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
PKGREVISION=	1
COMMENT=	Machine independent files for Freeciv

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../games/freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--enable-make-data

.include "../../mk/bsd.pkg.mk"
