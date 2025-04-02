# $NetBSD: options.mk,v 1.1 2025/04/02 13:03:14 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libheif
PKG_SUPPORTED_OPTIONS=	aom x265
PKG_SUGGESTED_OPTIONS=	aom x265

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maom)
CMAKE_CONFIGURE_ARGS+=	-DWITH_AOM_DECODER=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_AOM_ENCODER=ON
.  include "../../multimedia/libaom/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_AOM_DECODER=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_AOM_ENCODER=OFF
.endif

.if !empty(PKG_OPTIONS:Mx265)
CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBDE265=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_X265=ON
.  include "../../multimedia/libde265/buildlink3.mk"
.  include "../../multimedia/x265/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_LIBDE265=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_X265=OFF
.endif
