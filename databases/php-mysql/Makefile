# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:14 jdolecek Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

USE_BUILDLINK3=		yes
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
