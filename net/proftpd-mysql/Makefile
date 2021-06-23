# $NetBSD: Makefile,v 1.2 2021/06/23 20:33:15 nia Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	mysql
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}/}
PKGREVISION=	1
COMMENT=	MySQL module for proftpd

CONFIGURE_ARGS+=	--with-shared=mod_sql_mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
