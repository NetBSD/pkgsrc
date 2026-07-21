# $NetBSD: options.mk,v 1.12 2026/07/21 15:47:06 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geeqie
PKG_SUPPORTED_OPTIONS=		gspell libarchive libchamplain libraw libwebp pdf # gtk4
PKG_SUGGESTED_OPTIONS=		# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgspell)
.include "../../textproc/gspell/buildlink3.mk"
.endif

#.if !empty(PKG_OPTIONS:Mgtk4)
## doesn't build as of 2.9
#MESON_ARGS+=	-Dgtk4=enabled
#.include "../../x11/gtk4/buildlink3.mk"
#.else
#.include "../../x11/gtk3/buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mlibarchive)
.include "../../archivers/libarchive/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibchamplain)
# While clutter is optional, the map requires it.
.include "../../graphics/clutter/buildlink3.mk"
.include "../../geography/libchamplain012/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibraw)
.include "../../graphics/libraw/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibwebp)
.include "../../graphics/libwebp/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpdf)
.include "../../print/poppler/buildlink3.mk"
.endif
