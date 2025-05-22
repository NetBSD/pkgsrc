# $NetBSD: options.mk,v 1.1 2025/05/22 21:09:09 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.threadingbuildingblocks
PKG_SUPPORTED_OPTIONS=		tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
TEST_TARGET=		test
# For Darwin
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/pkgsrc_relwithdebinfo
.else
CMAKE_CONFIGURE_ARGS+=	-DTBB_TEST=OFF
.endif
