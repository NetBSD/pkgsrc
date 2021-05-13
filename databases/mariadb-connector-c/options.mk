# $NetBSD: options.mk,v 1.2 2021/05/13 11:46:13 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mariadb-connector-c
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl
PKG_SUPPORTED_OPTIONS=		curl kerberos
PKG_SUGGESTED_OPTIONS=		openssl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	curl gss openssl ssl

.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.ssl=	yes
CMAKE_ARGS+=	-DWITH_SSL=GNUTLS
.  include "../../security/gnutls/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopenssl)
PLIST.openssl=	yes
PLIST.ssl=	yes
CMAKE_ARGS+=	-DWITH_SSL=OPENSSL
.  include "../../security/openssl/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_SSL=OFF
.endif

.if !empty(PKG_OPTIONS:Mcurl)
PLIST.curl=	yes
.  include "../../www/curl/buildlink3.mk"
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_CURL=ON
CMAKE_ARGS+=	-DREMOTEIO_PLUGIN_TYPE=OFF
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
PLIST.gss=	yes
.  include "../../mk/krb5.buildlink3.mk"
.else
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_GSSAPI=ON
CMAKE_ARGS+=	-DAUTH_GSSAPI_PLUGIN_TYPE=OFF
.endif
