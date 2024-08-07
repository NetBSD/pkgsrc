# $NetBSD: options.mk,v 1.4 2024/08/07 09:39:06 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcsc-lite

PKG_SUPPORTED_OPTIONS=		polkit
PKG_SUGGESTED_OPTIONS=		polkit

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	polkit

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
MESON_ARGS+=		-Dpolkit=true
PLIST.polkit=		yes
.else
MESON_ARGS+=		-Dpolkit=false
.endif
