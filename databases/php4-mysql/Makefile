# $NetBSD: Makefile,v 1.15 2004/10/29 05:59:23 jdolecek Exp $

MODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

USE_BUILDLINK3=		yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
