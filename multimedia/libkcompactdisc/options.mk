# $NetBSD: options.mk,v 1.1 2013/04/03 12:23:51 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libkcompactdisc
PKG_SUPPORTED_OPTIONS=	alsa
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=OFF
.endif
