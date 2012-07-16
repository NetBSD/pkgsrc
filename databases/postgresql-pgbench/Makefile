# $NetBSD: Makefile,v 1.1.1.1 2012/07/16 15:32:47 asau Exp $

PKGNAME=	${DISTNAME:C/-/${PGSQL_VERSION}-pgbench-/}
COMMENT=	PostgreSQL benchmarking tools

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS+=		contrib/pgbench

.include "../../mk/pgsql.buildlink3.mk" # this one defines PGSQL_VERSION among others
.include "../../databases/postgresql${PGSQL_VERSION}/Makefile.common"
.include "../../mk/bsd.pkg.mk"
