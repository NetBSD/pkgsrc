# $NetBSD: options.mk,v 1.2 2025/05/19 11:11:14 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ufraw
PKG_SUPPORTED_OPTIONS=	lensfun
PKG_SUGGESTED_OPTIONS=	lensfun

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlensfun)
.include "../../graphics/lensfun/buildlink3.mk"
.endif
