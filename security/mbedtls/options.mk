# $NetBSD: options.mk,v 1.4 2020/07/07 11:16:10 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mbedtls
PKG_SUPPORTED_OPTIONS=	zlib
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
.  include "../../devel/zlib/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_ZLIB_SUPPORT=ON
.else
CMAKE_ARGS+=	-DENABLE_ZLIB_SUPPORT=OFF
.endif
