# $NetBSD: options.mk,v 1.1 2015/03/28 19:00:28 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.polarssl
PKG_SUPPORTED_OPTIONS=	tests zlib
PKG_SUGGESTED_OPTIONS+=	# XXX: blank, though the package has "tests" by default
PLIST_VARS+=		tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
.include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=		-DENABLE_TESTING=ON
PLIST.tests=		yes
.else
CMAKE_ARGS+=		-DENABLE_TESTING=OFF
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
CMAKE_ARGS+=		-DENABLE_ZLIB_SUPPORT=ON
.else
CMAKE_ARGS+=		-DENABLE_ZLIB_SUPPORT=OFF
.endif
