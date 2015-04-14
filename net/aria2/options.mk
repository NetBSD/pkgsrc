# $NetBSD: options.mk,v 1.16 2015/04/14 15:50:38 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.aria2

PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_OPTIONS_REQUIRED_GROUPS=	ssl

PKG_SUPPORTED_OPTIONS=		nls sqlite
PKG_SUGGESTED_OPTIONS=		nls sqlite ssl
PLIST_VARS+=			nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

###
###	SSL/TLS implementation
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--with-gnutls=no
.  include "../../security/openssl/buildlink3.mk"
USE_TOOLS+=		pkg-config
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
