# $NetBSD: Makefile,v 1.16 2004/10/31 17:45:44 jdolecek Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

USE_PHP_EXT_PATCHES=	yes

.include "../../www/php4/Makefile.module"

USE_BUILDLINK3=		yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
