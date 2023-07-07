# $NetBSD: Makefile,v 1.3 2023/07/07 11:46:49 jperkin Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	mysql
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
COMMENT=	MySQL module for proftpd

CONFIGURE_ARGS+=	--with-shared=mod_sql_mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
