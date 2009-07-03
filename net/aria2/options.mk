# $NetBSD: options.mk,v 1.8 2009/07/03 10:31:30 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.aria2

PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_OPTIONS_REQUIRED_GROUPS=	ssl

PKG_SUPPORTED_OPTIONS=		sqlite firefox3
PKG_SUGGESTED_OPTIONS=		ssl
###
### XXX Remove this in the future [2008-04-15 bjs]
###
.if !empty(PKG_OPTIONS.aria2:U:Maria2-metalink) || \
	!empty(PKG_DEFAULT_OPTIONS:U:Maria2-metalink)
PKG_OPTIONS_DEPRECATED_WARNINGS+=\
	"NOTE:	The aria2-metalink option is deprecated; this package"\
"	now supports the metalink protocol by default."
.endif

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
.  include "../../security/gnutls/libgnutls-config.mk"
.endif
###
###	firefox3 cookie	support via sqlite3
###
.if !empty(PKG_OPTIONS:Mfirefox3) || !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite3
CONFIGURE_ARGS+=	--with-sqlite3-prefix=${BUILDLINK_PREFIX.sqlite:Q}
.  include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-sqlite3=no
.endif
