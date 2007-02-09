# $NetBSD: options.mk,v 1.2 2007/02/09 20:32:38 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.daapd
PKG_SUPPORTED_OPTIONS=	mpeg4ip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpeg4ip)
.include "../../multimedia/libmp4v2/buildlink3.mk"
MAKE_ENV+= WITH_FAAD=1
.else
MAKE_ENV+= WITH_FAAD=0
.endif
