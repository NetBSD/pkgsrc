# $NetBSD: options.mk,v 1.3 2026/07/01 22:14:21 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libwebp
PKG_SUPPORTED_OPTIONS=	tiff
PKG_SUGGESTED_OPTIONS=	tiff

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtiff)
.include "../../graphics/tiff/buildlink3.mk"
.endif
