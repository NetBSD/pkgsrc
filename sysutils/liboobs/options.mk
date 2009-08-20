# $NetBSD: options.mk,v 1.1 2009/08/20 09:13:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboobs
PKG_SUPPORTED_OPTIONS+=	hal
PKG_SUGGESTED_OPTIONS+=	hal

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif
