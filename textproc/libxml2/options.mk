# $NetBSD: options.mk,v 1.4 2026/01/01 10:02:49 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxml2
PKG_SUPPORTED_OPTIONS+=	icu

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
CONFIGURE_ARGS+=	--with-icu
.else
CONFIGURE_ARGS+=	--without-icu
.endif
