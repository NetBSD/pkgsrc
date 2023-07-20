# $NetBSD: options.mk,v 1.1 2023/07/20 21:40:53 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.prometheus-cpp

# Tests are not installed, so default off.
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
TEST_TARGET=	test
CMAKE_ARGS+=	-DENABLE_TESTING=ON
# XXX: it's using an internal copy...
#.  include "../../devel/googletest/buildlink3.mk"
.else
CMAKE_ARGS+=	-DENABLE_TESTING=OFF
.endif
