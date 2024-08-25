# $NetBSD: options.mk,v 1.3 2024/08/25 06:19:05 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x265
PKG_SUPPORTED_OPTIONS=	x265-main10

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx265-main10)
CMAKE_CONFIGURE_ARGS+=	-DHIGH_BIT_DEPTH=ON
.endif
