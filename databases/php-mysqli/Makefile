# $NetBSD: Makefile,v 1.12 2015/04/16 20:27:09 ryoon Exp $

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
.  if !empty(_MYSQL_VERSION:MMARIADB*)
EVAL_PREFIX+=		MYSQLDIR=mariadb-client
CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.mariadb-client}/bin/mysql_config
.  else
EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
.  endif
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
