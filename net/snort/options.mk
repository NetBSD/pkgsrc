# $NetBSD: options.mk,v 1.1 2007/02/17 19:08:48 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snort

PKG_SUPPORTED_OPTIONS=	debug snort-prelude
PKG_SUGGESTED_OPTIONS=

PKG_OPTIONS_OPTIONAL_GROUPS=	flex
PKG_OPTIONS_GROUP.flex= 	snort-flexresp snort-flexresp2

PKG_OPTIONS_OPTIONAL_GROUPS+=	database
PKG_OPTIONS_GROUP.database= 	mysql pgsql

.include "../../mk/bsd.options.mk"

###
### Enable debug support
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

###
### Support MySQL for snort logging
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LDFLAGS+=		${BUILDLINK_LDFLAGS.mysql-client}
.endif

###
### Support PostgreSQL for snort logging
###
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX:Q}
.endif

###
### Enable Prelude support (untested)
###
.if !empty(PKG_OPTIONS:Mprelude)
.include "../../security/libprelude/buildlink3.mk"
.include "../../security/libpreludedb/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-prelude
.endif

###
### Flexible Responses on hostile connection attempts (untested)
###
.if !empty(PKG_OPTIONS:Mflexresp)
CONFIGURE_ARGS+=	--enable-flexresp
.include "../../devel/libnet/buildlink3.mk"
.endif

###
### NEW Flexible Responses on hostile connection attempts (untested)
###
.if !empty(PKG_OPTIONS:Mflexresp2)
CONFIGURE_ARGS+=	--enable-flexresp2
.include "../../net/libdnet/buildlink3.mk"
.endif
