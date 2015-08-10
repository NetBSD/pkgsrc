# $NetBSD: Makefile,v 1.13 2015/08/10 12:56:27 manu Exp $

MODNAME=		mysqli
CATEGORIES+=		databases
COMMENT=		PHP5 extension for MySQL 4.1 and later databases

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS=	php-mysqli-[0-9]*

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-mysqli
PKG_SUPPORTED_OPTIONS=	mysqlnd
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysqlnd)
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,mysqlnd
.else
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
