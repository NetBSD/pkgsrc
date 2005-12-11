# $NetBSD: options.mk,v 1.1 2005/12/11 11:09:06 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.faac
PKG_SUPPORTED_OPTIONS=	faad
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
.endif
