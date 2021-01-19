# $NetBSD: options.mk,v 1.1 2021/01/19 08:12:05 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.icingaweb2
PKG_OPTIONS_NONEMPTY_SETS=	ido
PKG_OPTIONS_SET.ido=		mysql pgsql
PKG_SUGGESTED_OPTIONS+=		pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli-[0-9]*:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo-[0-9]*:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql-[0-9]*:../../databases/php-pdo_pgsql
.endif
