# $NetBSD: options.mk,v 1.5 2020/08/08 19:11:13 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	icu
PKG_SUGGESTED_OPTIONS=	icu

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		icu

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
MESON_ARGS+=	-Dicu=enabled
.else
MESON_ARGS+=	-Dicu=disabled
.endif
