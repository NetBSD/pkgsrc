# $NetBSD: Makefile,v 1.2 2004/11/05 21:44:44 jdolecek Exp $

MODNAME=		mysqli
CATEGORIES+=		databases
COMMENT=		PHP5 extension for MySQL 4.1 and later databases

MAINTAINER=		jdolecek@NetBSD.org

USE_BUILDLINK3=		yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}/bin/mysql_config

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"

MYSQL_VERSION_REQD=	41
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
