# $NetBSD: options.mk,v 1.14 2005/12/05 20:49:58 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openldap
PKG_SUPPORTED_OPTIONS=	bdb kerberos sasl slp
PKG_SUGGESTED_OPTIONS=	bdb

.include "../../mk/bsd.options.mk"

###
### Whether to build with the Berkeley DB based slapd backends.
###
### NOTE: that option is enabled, because the openldap server needs
### 	  to have local storage support to work as standalone.
###

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db4 # db3?
.  include "../../mk/bdb.buildlink3.mk"
.endif
BDB_TYPE?=		none
.if ${BDB_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-bdb --enable-hdb
.else
CONFIGURE_ARGS+=	--disable-bdb --disable-hdb
.endif

###
### Kerberos authentication is via SASL.
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Msasl)
PKG_OPTIONS+=		sasl
.  endif
.endif

###
### SASL authentication (requires SASL2)
###
.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=		--with-cyrus-sasl
BUILDLINK_DEPENDS.cyrus-sasl+=  cyrus-sasl>=2.1.15
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-cyrus-sasl
.endif

###
### SLP (Service Locator Protocol)
###
.if !empty(PKG_OPTIONS:Mslp)
.  include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-slp
.endif
