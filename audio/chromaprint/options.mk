# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:22 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.chromaprint

# Tests are not installed, so default off.
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
# googletest requires at least C++14. It bundles its own copy.
USE_CXX_FEATURES+=	c++14
TEST_TARGET=		check
CMAKE_CONFIGURE_ARGS+=		-DBUILD_TESTS=ON
.else
CMAKE_CONFIGURE_ARGS+=		-DBUILD_TESTS=OFF
.endif
