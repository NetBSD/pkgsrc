# $NetBSD: options.mk,v 1.1 2023/04/27 22:02:33 nikita Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libnitrokey

PKG_SUPPORTED_OPTIONS+=		doc tests

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mdoc}
DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
# else switch this off in cmake
.endif

.if ${PKG_OPTIONS:Mtests}
# These tests do not require any device to be connected
CMAKE_ARGS+=	-DCOMPILE_OFFLINE_TESTS=ON
TEST_DEPENDS+=	catch2-[0-9]*:../../devel/catch2
.endif
