# $NetBSD: options.mk,v 1.9 2022/11/21 11:58:47 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geeqie
PKG_SUPPORTED_OPTIONS=		gtk3 libchamplain
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibchamplain)
# While clutter is optional, the map requires it.
.include "../../graphics/clutter/buildlink3.mk"
.include "../../geography/libchamplain012/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
.endif
