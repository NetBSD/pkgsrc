# $NetBSD: options.mk,v 1.1 2007/01/30 07:05:58 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.daapd
PKG_SUPPORTED_OPTIONS=	mpeg4ip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpeg4ip)
.include "../../multimedia/mpeg4ip/buildlink3.mk"
MAKE_ENV+= WITH_FAAD=1
.else
MAKE_ENV+= WITH_FAAD=0
.endif
