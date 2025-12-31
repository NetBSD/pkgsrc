# $NetBSD: options.mk,v 1.1 2025/12/31 13:35:44 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sayaka
PKG_SUPPORTED_OPTIONS=	jxl tiff
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjxl)
.include "../../graphics/libjxl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
.endif
