# $NetBSD: Makefile,v 1.1.1.1 2004/11/01 22:08:43 jdolecek Exp $

MODNAME=		mysqli
CATEGORIES+=		databases
COMMENT=		PHP5 extension for MySQL 4.1 and later databases

MAINTAINER=		jdolecek@NetBSD.org

USE_BUILDLINK3=		yes

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}/bin/mysql_config

MYSQL_VERSION_REQD=	41
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
