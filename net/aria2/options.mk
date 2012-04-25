# $NetBSD: options.mk,v 1.13 2012/04/25 15:59:59 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.aria2

PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_OPTIONS_REQUIRED_GROUPS=	ssl

PKG_SUPPORTED_OPTIONS=		sqlite
PKG_SUGGESTED_OPTIONS=		ssl sqlite

.include "../../mk/bsd.options.mk"
###
###	SSL/TLS implementation
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-gnutls=no
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-gnutls
CONFIGURE_ARGS+=	--with-openssl=no
.  include "../../security/gnutls/buildlink3.mk"
USE_TOOLS+=		pkg-config
.endif
###
###	firefox3 cookie	support via sqlite3
###
.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite3
CONFIGURE_ARGS+=	--with-sqlite3-prefix=${BUILDLINK_PREFIX.sqlite}
.  include "../../databases/sqlite3/buildlink3.mk"
USE_TOOLS+=		pkg-config
.else
CONFIGURE_ARGS+=	--with-sqlite3=no
.endif
