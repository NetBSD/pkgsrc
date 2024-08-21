# $NetBSD: options.mk,v 1.3 2024/08/21 11:34:22 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libkcompactdisc
PKG_SUPPORTED_OPTIONS=	alsa
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_ALSA:BOOL=TRUE
.endif
