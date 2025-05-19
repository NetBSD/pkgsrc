# $NetBSD: options.mk,v 1.4 2025/05/19 12:52:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.prometheus-cpp

# Tests are not installed, so default off.
PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
TEST_TARGET=		test
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTING=ON
# needed for pull test
ALLOW_NETWORK_ACCESS=	yes
# XXX: it's using an internal copy...
#.  include "../../devel/googletest/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTING=OFF
.endif
