# $NetBSD: options.mk,v 1.1 2016/06/16 09:21:11 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mbedtls
PKG_SUPPORTED_OPTIONS=	mbedtls-tools tests zlib
PKG_SUGGESTED_OPTIONS+=	# XXX: blank, though the package has "tests" by default

PLIST_VARS+=		tests tools

.if defined(PKG_OPTIONS.polarssl)
PKG_LEGACY_OPTIONS+=			${PKG_OPTIONS.polarssl}
PKG_OPTIONS_DEPRECATED_WARNINGS+=	"Deprecated variable PKG_OPTIONS.polarssl used, use "${PKG_OPTIONS_VAR:Q}" instead."
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmbedtls-tools)
CMAKE_ARGS+=		-DENABLE_PROGRAMS=ON
PLIST.tools=		yes
.else
CMAKE_ARGS+=		-DENABLE_PROGRAMS=OFF
.endif

.if !empty(PKG_OPTIONS:Mtests)
. if !empty(PKG_OPTIONS:Mmbedtls-tools)
.  include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=		-DENABLE_TESTING=ON
PLIST.tests=		yes
. else
PKG_FAIL_REASON+=	"option tests needs option mbedtls-tools"
. endif
.else
CMAKE_ARGS+=		-DENABLE_TESTING=OFF
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
CMAKE_ARGS+=		-DENABLE_ZLIB_SUPPORT=ON
.else
CMAKE_ARGS+=		-DENABLE_ZLIB_SUPPORT=OFF
.endif
