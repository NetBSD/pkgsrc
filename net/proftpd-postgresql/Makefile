# $NetBSD: Makefile,v 1.2.4.1 2017/04/05 21:54:26 spz Exp $

.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	postgresql
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}${PGSQL_VERSION}/}
COMMENT=	PostgreSQL module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_sql_postgres

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
