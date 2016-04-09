# $NetBSD: Makefile,v 1.7 2016/04/09 12:51:47 adam Exp $

PKGNAME=	${DISTNAME:C/-/93-monitoring-/}
COMMENT=	PostgreSQL monitoring tools

DEPENDS+=	postgresql93-server>=${PKGVERSION_NOREV}:../../databases/postgresql93-server

.include "../../databases/postgresql93/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS+=		contrib/auto_explain
BUILD_DIRS+=		contrib/pg_buffercache
BUILD_DIRS+=		contrib/pg_stat_statements
BUILD_DIRS+=		contrib/pg_test_timing
BUILD_DIRS+=		contrib/pgstattuple

.include "../../databases/postgresql93-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
