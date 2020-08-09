# $NetBSD: options.mk,v 1.6 2020/08/09 00:53:12 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	icu
PKG_SUGGESTED_OPTIONS=	icu

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		icu

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
MESON_ARGS+=	-Dicu=enabled
PLIST.icu=		yes
.else
MESON_ARGS+=	-Dicu=disabled
.endif
