# $NetBSD: Makefile,v 1.11 2004/03/31 10:11:46 tron Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

DISTINFO_FILE=		${PKGDIR}/distinfo

.include "../../www/php4/Makefile.module"

USE_BUILDLINK2=		# defined

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,${RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
