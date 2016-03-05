# $NetBSD: Makefile,v 1.3 2016/03/05 16:06:32 tnn Exp $

PKGNAME=	${DISTNAME:C/-/${PGSQL_VERSION}-pgbench-/}
COMMENT=	PostgreSQL benchmarking tools

BUILD_DIRS+=		contrib/pgbench

.include "../../mk/pgsql.buildlink3.mk" # this one defines PGSQL_VERSION among others

# This package should be removed when PGSQL_VERSION_DEFAULT is bumped
.if !empty(PGSQL_VERSION:M95)
PKG_SKIP_REASON+=	\
	"pgbench is now shipped with postgresql${PGSQL_VERSION}-client"
.endif

.include "../../databases/postgresql${PGSQL_VERSION}/Makefile.common"
.include "../../mk/bsd.pkg.mk"
