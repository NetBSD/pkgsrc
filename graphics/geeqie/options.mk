# $NetBSD: options.mk,v 1.11 2024/01/26 14:13:01 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geeqie
PKG_SUPPORTED_OPTIONS=		gspell libarchive libchamplain libraw libwebp pdf
PKG_SUGGESTED_OPTIONS=		# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgspell)
.include "../../textproc/gspell/buildlink3.mk"
.endif

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
