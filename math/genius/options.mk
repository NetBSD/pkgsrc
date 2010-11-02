# $NetBSD: options.mk,v 1.2 2010/11/02 18:02:34 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.genius
PKG_SUPPORTED_OPTIONS=		x11
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif
