# $NetBSD: Makefile,v 1.23 2002/07/26 17:36:24 wiz Exp $

.include "Makefile.common"

PKGREVISION=	1

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-zvt

CONFLICTS+=		xchat-gnome-[0-9]*

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
