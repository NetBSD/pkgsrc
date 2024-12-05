# $NetBSD: options.mk,v 1.1 2024/12/05 08:29:16 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensmtpd-tables

PKG_SUPPORTED_OPTIONS+=	ldap mysql pgsql redis sqlite
PKG_SUGGESTED_OPTIONS=	ldap sqlite

.include "../../mk/bsd.options.mk"

###
### SQLite table
###
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	opensmtpd-table-sqlite-[0-9]*:../../mail/opensmtpd-table-sqlite
.endif

###
### LDAP table
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	opensmtpd-table-ldap-[0-9]*:../../mail/opensmtpd-table-ldap
.endif

###
### MySQL table
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	opensmtpd-table-mysql-[0-9]*:../../mail/opensmtpd-table-mysql
.endif

###
### PostgreSQL table
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	opensmtpd-table-postgres-[0-9]*:../../mail/opensmtpd-table-postgres
.endif

###
### Redis table
###
.if !empty(PKG_OPTIONS:Mredis)
DEPENDS+=	opensmtpd-table-redis-[0-9]*:../../mail/opensmtpd-table-redis
.endif
