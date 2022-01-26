# $NetBSD: options.mk,v 1.2 2022/01/26 16:41:45 tm Exp $

PKG_OPTIONS_VAR=			PKG_OPTIONS.SOPE

PKG_SUPPORTED_OPTIONS=			ldap
PKG_OPTIONS_REQUIRED_GROUPS=		database
PKG_OPTIONS_GROUP.database=		mysql pgsql

PKG_SUGGESTED_OPTIONS=			ldap pgsql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=				pgsql mysql ldap

.if !empty(PKG_OPTIONS:Mmysql)
pre-configure:
	${TEST} -e ${BUILDLINK_DIR}/lib/libmysqlclient.so || \
	${LN} -s ${BUILDLINK_DIR}/lib/mysql/libmysqlclient.so \
	${BUILDLINK_DIR}/lib/libmysqlclient.so
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql= 				yes
.else
CONFIGURE_ARGS+=			--disable-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
PLIST.pgsql= 				yes
.else
CONFIGURE_ARGS+=			--disable-postgresql
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=				yes
.else
CONFIGURE_ARGS+=			--disable-openldap
.endif
