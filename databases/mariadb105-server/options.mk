# $NetBSD: options.mk,v 1.1 2021/05/23 15:32:48 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql-server

PKG_SUPPORTED_OPTIONS+=	embedded-server ssl
PKG_SUGGESTED_OPTIONS+=	embedded-server ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Membedded-server)
CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER=ON
PLIST_SRC+=	PLIST.embedded
.else
CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER=OFF
.endif

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SSL=system
LDFLAGS+=	-lcrypto -lssl
.else
CMAKE_ARGS+=	-DWITH_SSL=no
.endif
