# $NetBSD: options.mk,v 1.25 2021/08/23 09:58:59 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openldap-server
PKG_SUPPORTED_OPTIONS=		dso inet6 sasl slapi slp
PKG_OPTIONS_OPTIONAL_GROUPS+=	odbc
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc
PKG_SUGGESTED_OPTIONS=		dso inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	slapi

###
### Whether to build with iODBC to enable SQL based slapd backends
###
.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-sql
.endif

###
### Whether to build with unixODBC to enable SQL based slapd backends
###
.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
.  include "../../devel/libltdl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-sql
.endif

.if empty(PKG_OPTIONS:Miodbc) && empty(PKG_OPTIONS:Munixodbc)
CONFIGURE_ARGS+=	--disable-sql
.endif

###
### SASL authentication (requires SASL2)
###
.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=		--with-cyrus-sasl
CONFIGURE_ARGS+=		--enable-spasswd
BUILDLINK_API_DEPENDS.cyrus-sasl+=	cyrus-sasl>=2.1.15
.  include "../../security/cyrus-sasl/buildlink3.mk"
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

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### Enable dynamic module support
###
.if !empty(PKG_OPTIONS:Mdso)
CONFIGURE_ARGS+=	--enable-modules
.include "../../devel/libltdl/buildlink3.mk"
.endif

###
### Enable SLAPI support
###
.if !empty(PKG_OPTIONS:Mslapi)
CONFIGURE_ARGS+=	--enable-slapi
PLIST.slapi=		yes
.include "../../devel/libltdl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-slapi
.endif
