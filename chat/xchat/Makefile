# $NetBSD: Makefile,v 1.27 2003/10/03 07:20:00 xtraeme Exp $

.include "Makefile.common"

# Don't set "PKGREVISION" here, set it in "Makefile.common".

CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-zvt

CONFLICTS+=		xchat-gnome-[0-9]* xchat-2.[0-9]*

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
