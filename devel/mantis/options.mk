# $NetBSD: options.mk,v 1.4 2016/09/01 13:22:45 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mantis
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql
PKG_SUPPORTED_OPTIONS=		charts ldap
PKG_SUGGESTED_OPTIONS+=		mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PHP_PKG_PREFIX}-ldap-[0-9]*:../../databases/php-ldap
.endif

.if !empty(PKG_OPTIONS:Mcharts)
DEPENDS+=	${PHP_PKG_PREFIX}-jpgraph-[0-9]*:../../graphics/php-jpgraph
.endif

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql-[0-9]*:../../databases/php-pgsql
.endif
