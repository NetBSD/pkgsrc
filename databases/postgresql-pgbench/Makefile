# $NetBSD: Makefile,v 1.5 2016/11/23 13:39:28 fhajny Exp $

PKGNAME=	${DISTNAME:C/-/${PGSQL_VERSION}-pgbench-/}
PKGREVISION=	1
COMMENT=	PostgreSQL benchmarking tools

BUILD_DIRS+=		contrib/pgbench

.include "../../mk/pgsql.buildlink3.mk" # this one defines PGSQL_VERSION among others

# This package is only to be used with PostgreSQL<9.5
.if empty(PGSQL_VERSION:M9[1234])
PKG_SKIP_REASON+=	\
	"pgbench is now shipped with postgresql${PGSQL_VERSION}-client"
.endif

.include "../../databases/postgresql${PGSQL_VERSION}/Makefile.common"
.include "../../mk/bsd.pkg.mk"
