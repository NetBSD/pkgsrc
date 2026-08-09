# $NetBSD: options.mk,v 1.13 2026/08/09 17:28:28 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geeqie
PKG_SUPPORTED_OPTIONS=		libarchive libraw libshumate libwebp pdf
PKG_SUGGESTED_OPTIONS=		# none

.include "../../mk/bsd.options.mk"

# TODO libspelling option, when package exists

.if !empty(PKG_OPTIONS:Mlibarchive)
.include "../../archivers/libarchive/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibraw)
.include "../../graphics/libraw/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibshumate)
.include "../../geography/libshumate/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibwebp)
.include "../../graphics/libwebp/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpdf)
.include "../../print/poppler/buildlink3.mk"
.endif
