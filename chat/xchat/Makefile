# $NetBSD: Makefile,v 1.25 2002/09/21 23:52:55 jlam Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-zvt

CONFLICTS+=		xchat-gnome-[0-9]*

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
