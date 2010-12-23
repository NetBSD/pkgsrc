# $NetBSD: Makefile,v 1.13.2.1 2010/12/23 10:10:55 sbd Exp $

MODNAME=		mysql
CATEGORIES+=		databases
COMMENT=		PHP extension for MySQL databases

MAINTAINER=		pkgsrc-users@NetBSD.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-mysql-[0-9]*

USE_PHP_EXT_PATCHES=	yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
CONFIGURE_ENV+=		CPP=${CPP:Q}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../lang/php/ext.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
