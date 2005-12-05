# $NetBSD: Makefile,v 1.5 2005/12/05 20:49:58 rillig Exp $

MODNAME=		mysql
CATEGORIES+=		databases
COMMENT=		PHP extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

USE_PHP_EXT_PATCHES=	yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
