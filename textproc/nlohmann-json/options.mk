# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:16 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nlohmann-json

PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	tests
.if !empty(PKG_OPTIONS:Mtests)
# FIXME: Downloads test data from a fixed tag in a git repository,
# package https://github.com/nlohmann/json_test_data to prevent downloads.
# FIXME: A small number of tests assume that WRKSRC is a git checkout.
PLIST.tests=	yes
TEST_TARGET=	test
CMAKE_CONFIGURE_ARGS+=	-DJSON_BuildTests=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DJSON_BuildTests=OFF
.endif
