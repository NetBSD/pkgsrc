# $NetBSD: Makefile,v 1.57 2008/06/20 01:09:12 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

CONFLICTS+=		glade-gnome-[0-9]*

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-gnome-db

.include "../../mk/bsd.pkg.mk"
