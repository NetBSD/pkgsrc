# $NetBSD: options.mk,v 1.1 2025/03/05 22:26:18 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.p11-kit
PKG_SUPPORTED_OPTIONS=		tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
MESON_ARGS+=		-Dtest=true
.else
MESON_ARGS+=		-Dtest=false
.endif
