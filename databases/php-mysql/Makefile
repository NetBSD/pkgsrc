# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:14 tv Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

USE_PHP_EXT_PATCHES=	yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
