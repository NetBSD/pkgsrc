# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 05:54:01 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		mysql
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for MySQL databases

DEPENDS+=		mysql-client>=3.23.35:../../databases/mysql-client

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../mk/bsd.pkg.mk"
