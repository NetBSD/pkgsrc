# $NetBSD: options.mk,v 1.1 2022/08/11 06:49:16 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mbedtls3
PKG_SUPPORTED_OPTIONS=	zlib
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
.  include "../../devel/zlib/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_ZLIB_SUPPORT=ON
.else
CMAKE_ARGS+=	-DENABLE_ZLIB_SUPPORT=OFF
.endif
