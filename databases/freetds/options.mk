# $NetBSD: options.mk,v 1.8 2012/01/09 14:53:31 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freetds
PKG_OPTIONS_OPTIONAL_GROUPS+=	odbc tls
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc
PKG_OPTIONS_GROUP.tls=		gnutls openssl
PKG_SUPPORTED_OPTIONS=		kerberos
PKG_SUGGESTED_OPTIONS=		openssl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			odbc

###
### Kerberos5 support
###
.if !empty(PKG_OPTIONS:Mkerberos)
CONFIGURE_ARGS+=	--enable-krb5
.include "../../mk/krb5.buildlink3.mk"
.endif

###
### Whether to build with iODBC to enable ODBC access to TDS servers.
###
.if !empty(PKG_OPTIONS:Miodbc)
ODBC_DRIVER=		yes
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--with-iodbc=${BUILDLINK_PREFIX.iodbc}
PLIST.odbc=		yes
.endif

###
### Whether to build with unixODBC to enable ODBC access to TDS servers.
###
.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--with-unixodbc=${BUILDLINK_PREFIX.unixodbc}
PLIST.odbc=		yes
.endif

.if empty(PKG_OPTIONS:Miodbc) && empty(PKG_OPTIONS:Munixodbc)
CONFIGURE_ARGS+=	--disable-odbc
.endif

###
### Use GNU TLS for TLSv1 encrypted session to MSSQL servers.
###
.if !empty(PKG_OPTIONS:Mgnutls)
USE_TOOLS+=	pkg-config
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

###
### Use OpenSSL for TLSv1 encrypted session to MSSQL servers.
###
.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
