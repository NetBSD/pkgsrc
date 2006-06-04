# $NetBSD: Makefile,v 1.7 2006/06/04 16:26:53 joerg Exp $

MODNAME=		mysqli
CATEGORIES+=		databases
COMMENT=		PHP5 extension for MySQL 4.1 and later databases

MAINTAINER=		jdolecek@NetBSD.org

CONFLICTS=	php-mysqli-[0-9]*

PHP_VERSIONS_ACCEPTED=	5

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}/bin/mysql_config

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
