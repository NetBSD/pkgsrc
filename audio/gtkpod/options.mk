# $NetBSD: options.mk,v 1.1 2005/11/15 16:12:33 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtkpod
PKG_SUPPORTED_OPTIONS=	faad
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
.endif
