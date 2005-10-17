# $NetBSD: options.mk,v 1.2 2005/10/17 14:09:12 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wine
PKG_SUPPORTED_OPTIONS=	arts cups sane

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msane)
.include "../../graphics/sane-backends/buildlink3.mk"
.endif
