# $NetBSD: Makefile,v 1.18 2010/06/21 07:53:14 spz Exp $

PKGNAME=	${DISTNAME:S/-/-share-/}
COMMENT=	Machine independent files for Freeciv

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../games/freeciv-share/Makefile.common"

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CONFIGURE_ARGS+=	--enable-make-data

.include "../../mk/bsd.pkg.mk"
