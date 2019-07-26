# $NetBSD: options.mk,v 1.4 2019/07/26 09:44:03 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.geeqie
PKG_OPTIONS_OPTIONAL_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3 
PKG_SUPPORTED_OPTIONS=		libchamplain
# The libchamplain option doesn't actually work, so leave it off
# to avoid the pain of dependencies with no benefit, until debugged.
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibchamplain)
CONFIGURE_ARGS+=	--enable-gps
CONFIGURE_ARGS+=	--enable-clutter
.include "../../geography/libchamplain04/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gps
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-gtk3
.include "../../x11/gtk3/buildlink3.mk"
.endif
