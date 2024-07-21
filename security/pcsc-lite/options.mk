# $NetBSD: options.mk,v 1.3 2024/07/21 01:02:26 manu Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcsc-lite

PKG_SUPPORTED_OPTIONS=		polkit
PKG_SUGGESTED_OPTIONS=		polkit

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
MESON_ARGS+=		-Dpolkit=true
PLIST_SUBST+=		POLKIT=""
.else
MESON_ARGS+=		-Dpolkit=false
PLIST_SUBST+=		POLKIT="@comment "
.endif

