# $NetBSD: options.mk,v 1.9 2005/01/12 01:50:15 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openldap
PKG_SUPPORTED_OPTIONS=	bdb dynamic kerberos sasl slp
PKG_DEFAULT_OPTIONS+=	bdb

.include "../../mk/bsd.options.mk"

###
### Whether to build with the Berkeley DB based slapd backends.
###
.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db4 # db3?
.  include "../../mk/bdb.buildlink3.mk"
.endif
BDB_TYPE?=		none
.if ${BDB_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-bdb --enable-hdb
.  if !empty(PKG_OPTIONS:Mdynamic)
CONFIGURE_ARGS+=	--enable-hdb=mod
.  endif
.else
CONFIGURE_ARGS+=	--disable-bdb --disable-hdb
.endif

###
### Whether to build with dynamically-loadable backend modules.  If not
### specified, then link the backend modules statically into slapd.
###
.if !empty(PKG_OPTIONS:Mdynamic)
.  if !empty(PKG_OPTIONS:Mbdb)
PLIST_SUBST+=		HDB_MODULE=
.  else
PLIST_SUBST+=		HDB_MODULE="@comment "
.  endif
.  include "../../devel/libltdl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-modules
PLIST_SUBST+=		DYNAMIC_MOD=
.else
PLIST_SUBST+=		DYNAMIC_MOD="@comment "
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
.endif

###
### SLP (Service Locator Protocol)
###
.if !empty(PKG_OPTIONS:Mslp)
.  include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-slp
.endif
