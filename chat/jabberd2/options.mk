# $NetBSD: options.mk,v 1.11 2006/05/31 18:22:23 ghen Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.jabberd2
PKG_SUPPORTED_OPTIONS=	db ldap pam
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb)
BUILD_DEFS+=		JABBERD_DBDIR
JABBERD_DBDIR?=         ${VARBASE}/db/jabberd
CONFIGURE_ARGS+=        --enable-db
.  include "../../databases/db4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=        --enable-mysql
CPPFLAGS+=              -I${BUILDLINK_PREFIX.mysql-client}/include/mysql
.  include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=        --enable-pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=        --enable-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=        --enable-pam
.  include "../../mk/pam.buildlink3.mk"
.endif
