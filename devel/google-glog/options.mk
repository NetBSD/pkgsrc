# $NetBSD: options.mk,v 1.3 2025/02/18 09:03:44 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.google-glog
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

# The following tests FAILED:
#     1 - logging_custom_prefix (Subprocess aborted)
#     3 - logging (Subprocess aborted)
#     7 - symbolize (Subprocess aborted)
#     11 - cmake_package_config_build (Failed)
.if !empty(PKG_OPTIONS:Mtests)
# googletest requires minimum c++14.
TEST_TARGET=	test
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=ON
.  include "../../devel/googletest/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
.endif
