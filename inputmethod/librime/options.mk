# $NetBSD: options.mk,v 1.2 2021/02/20 20:53:01 ryoon Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.librime
PKG_SUPPORTED_OPTIONS=		tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
.include "../../devel/googletest/buildlink3.mk"
CMAKE_ARGS+=	-DBUILD_TEST=ON
TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/lib
.else
CMAKE_ARGS+=	-DBUILD_TEST=OFF
.endif
