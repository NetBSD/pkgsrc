# $NetBSD: Makefile,v 1.14 2004/08/27 06:29:07 jlam Exp $

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

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
