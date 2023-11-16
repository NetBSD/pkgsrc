# $NetBSD: options.mk,v 1.1 2023/11/16 09:57:43 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.binaryen

PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
CMAKE_ARGS+=	-DBUILD_TESTS=ON
.  include "../../devel/googletest/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_TESTS=OFF
.endif
