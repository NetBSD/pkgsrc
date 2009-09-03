# $NetBSD: options.mk,v 1.1 2009/09/03 13:15:20 asau Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.genius
PKG_SUPPORTED_OPTIONS=		x11
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes

.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif
