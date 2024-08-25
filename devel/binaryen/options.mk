# $NetBSD: options.mk,v 1.3 2024/08/25 06:18:31 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.binaryen

PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	test
.if !empty(PKG_OPTIONS:Mtests)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=ON
.  include "../../devel/googletest/buildlink3.mk"
PLIST.test=	yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF
.endif
