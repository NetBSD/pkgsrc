# $NetBSD: Makefile,v 1.6 2003/01/02 23:35:43 lukem Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for MySQL databases

.include "../../www/php4/Makefile.module"

USE_BUILDLINK2=		# defined

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
