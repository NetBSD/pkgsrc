# $NetBSD: Makefile,v 1.9 2003/09/27 13:25:39 jdolecek Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for MySQL databases

.include "../../www/php4/Makefile.module"

USE_BUILDLINK2=		# defined

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,${RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
