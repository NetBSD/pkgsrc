# $NetBSD: options.mk,v 1.12 2025/06/13 06:46:19 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib ghostscript mng xpm
PKG_SUGGESTED_OPTIONS=	ghostscript mng xpm

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib ghostscript mng xpm

PRINT_PLIST_AWK+=       { if (/file-aa/) $$0 = "$${PLIST.aalib}" $$0 }
.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PLIST.aalib=		yes
.endif

PRINT_PLIST_AWK+=       { if (/file-ps$$/) $$0 = "$${PLIST.ghostscript}" $$0 }
.if !empty(PKG_OPTIONS:Mghostscript)
.include "../../print/ghostscript-agpl/buildlink3.mk"
PLIST.ghostscript=	yes
.else
MESON_ARGS+=	-Dghostscript=disabled
.endif

PRINT_PLIST_AWK+=       { if (/file-mng/) $$0 = "$${PLIST.mng}" $$0 }
.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST.mng=		yes
.endif

PRINT_PLIST_AWK+=       { if (/file-xpm/) $$0 = "$${PLIST.xpm}" $$0 }
.if !empty(PKG_OPTIONS:Mxpm)
.include "../../x11/libXpm/buildlink3.mk"
PLIST.xpm=		yes
.endif
