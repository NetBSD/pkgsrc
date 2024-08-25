# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:12 wiz Exp $

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
CMAKE_CONFIGURE_ARGS+=	-DCOMPILE_OFFLINE_TESTS=ON
TEST_DEPENDS+=	catch2-[0-9]*:../../devel/catch2
.endif
