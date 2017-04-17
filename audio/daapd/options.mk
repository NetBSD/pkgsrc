# $NetBSD: options.mk,v 1.3 2017/04/17 08:44:45 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.daapd
PKG_SUPPORTED_OPTIONS=	libmp4v2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibmp4v2)
.include "../../multimedia/libmp4v2/buildlink3.mk"
MAKE_ENV+= WITH_FAAD=1
.else
MAKE_ENV+= WITH_FAAD=0
.endif
