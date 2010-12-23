# $NetBSD: Makefile,v 1.2.2.1 2010/12/23 10:10:55 sbd Exp $

MODNAME=		mysqli
CATEGORIES+=		databases
COMMENT=		PHP5 extension for MySQL 4.1 and later databases

MAINTAINER=		jdolecek@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-mysqli-[0-9]*

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=${PREFIX}/bin/mysql_config

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
