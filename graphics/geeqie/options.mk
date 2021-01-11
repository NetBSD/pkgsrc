# $NetBSD: options.mk,v 1.8 2021/01/11 18:15:13 gdt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geeqie
PKG_OPTIONS_OPTIONAL_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3
PKG_SUPPORTED_OPTIONS=		libchamplain
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibchamplain)
# While clutter is optional, the map requires it.
CONFIGURE_ARGS+=	--enable-clutter
.include "../../graphics/clutter/buildlink3.mk"

CONFIGURE_ARGS+=	--enable-map
.include "../../geography/libchamplain012/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-map
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-gtk3
.include "../../x11/gtk3/buildlink3.mk"
.endif
