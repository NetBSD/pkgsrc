# $NetBSD: options.mk,v 1.1 2012/04/25 22:17:19 minskim Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.teTeX
PKG_SUPPORTED_OPTIONS+= x11
PKG_SUGGESTED_OPTIONS+= x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=      xdvik-[0-9]*:../../print/xdvik
.endif
