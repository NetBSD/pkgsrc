# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libhighway

PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
TEST_TARGET=	test
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=ON
BUILDLINK_API_DEPENDS.googletest+=	googletest>=1.10.0nb1
.  include "../../devel/googletest/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
.endif
