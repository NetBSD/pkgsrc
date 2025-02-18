# $NetBSD: options.mk,v 1.4 2025/02/18 10:05:00 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.librime
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
.include "../../devel/googletest/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TEST=ON
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/lib
# For Darwin
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/lib
TEST_TARGET=		test
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TEST=OFF
.endif
