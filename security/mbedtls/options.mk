# $NetBSD: options.mk,v 1.5 2024/08/25 06:19:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mbedtls
PKG_SUPPORTED_OPTIONS=	zlib
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
.  include "../../devel/zlib/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_ZLIB_SUPPORT=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_ZLIB_SUPPORT=OFF
.endif
