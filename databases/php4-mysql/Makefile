# $NetBSD: Makefile,v 1.4 2002/02/28 06:17:09 jlam Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for MySQL databases

DEPENDS+=		mysql-client>=3.23.35:../../databases/mysql-client

.include "../../www/php4/Makefile.module"

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../mk/bsd.pkg.mk"
