# $NetBSD: options.mk,v 1.4 2026/08/02 01:43:28 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.chromaprint

# Tests are not installed, so default off.
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
TEST_TARGET=		check
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF
.endif
