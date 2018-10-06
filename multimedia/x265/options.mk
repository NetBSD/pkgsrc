# $NetBSD: options.mk,v 1.2 2018/10/06 15:41:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.x265
PKG_SUPPORTED_OPTIONS=	x265-main10

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx265-main10)
CMAKE_ARGS+=	-DHIGH_BIT_DEPTH=ON
.endif
