# $NetBSD: Makefile,v 1.29 2004/04/26 22:07:06 snj Exp $

.include "Makefile.common"

# Don't set "PKGREVISION" here, set it in "Makefile.common".

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-zvt

CONFLICTS+=		xchat-gnome-[0-9]*

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
