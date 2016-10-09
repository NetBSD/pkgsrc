# $NetBSD: Makefile,v 1.2 2016/10/09 21:42:02 wiz Exp $

PKGREVISION= 1
.include "../../net/proftpd/Makefile.module"

PROFTPD_MOD=	postgresql
PKGNAME=	${DISTNAME:S/proftpd/proftpd-${PROFTPD_MOD}${PGSQL_VERSION}/}
COMMENT=	PostgreSQL module for ProFTPD

CONFIGURE_ARGS+=	--with-shared=mod_sql_postgres

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
