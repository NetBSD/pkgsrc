# $NetBSD: Makefile,v 1.8 2006/03/04 21:29:10 jlam Exp $

MODNAME=		mysql
PKGREVISION=		2
CATEGORIES+=		databases
COMMENT=		PHP extension for MySQL databases

MAINTAINER=		pkgsrc-users@NetBSD.org

USE_PHP_EXT_PATCHES=	yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
