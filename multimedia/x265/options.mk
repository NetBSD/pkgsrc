# $NetBSD: options.mk,v 1.1 2018/10/06 12:12:48 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x265
PKG_SUPPORTED_OPTIONS=	main10

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmain10)
CMAKE_ARGS+=	-DHIGH_BIT_DEPTH=ON
.endif
