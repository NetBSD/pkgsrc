# $NetBSD: options.mk,v 1.1 2026/08/10 07:30:58 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geeqie-gtk3
PKG_SUPPORTED_OPTIONS=		gspell libarchive libraw libwebp pdf # gtk4
PKG_SUGGESTED_OPTIONS=		# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgspell)
.include "../../textproc/gspell/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibarchive)
.include "../../archivers/libarchive/buildlink3.mk"
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
