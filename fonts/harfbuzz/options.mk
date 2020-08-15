# $NetBSD: options.mk,v 1.7 2020/08/15 21:48:34 szptvlfn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	doc icu
PKG_SUGGESTED_OPTIONS=	doc icu

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc icu

.if !empty(PKG_OPTIONS:Mdoc)
.include "../../textproc/gtk-doc/buildlink3.mk"
PLIST.doc=	yes
.endif

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
MESON_ARGS+=	-Dicu=enabled
PLIST.icu=		yes
.else
MESON_ARGS+=	-Dicu=disabled
.endif
