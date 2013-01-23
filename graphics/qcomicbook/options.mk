# $NetBSD: options.mk,v 1.1 2013/01/23 21:55:25 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qcomicbook
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Debug
.endif
