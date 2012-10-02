# $NetBSD: Makefile,v 1.2 2012/10/02 21:25:41 asau Exp $

PKGNAME=	${DISTNAME:C/-/${PGSQL_VERSION}-pgbench-/}
COMMENT=	PostgreSQL benchmarking tools

BUILD_DIRS+=		contrib/pgbench

.include "../../mk/pgsql.buildlink3.mk" # this one defines PGSQL_VERSION among others
.include "../../databases/postgresql${PGSQL_VERSION}/Makefile.common"
.include "../../mk/bsd.pkg.mk"
