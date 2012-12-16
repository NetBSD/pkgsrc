# $NetBSD: Makefile,v 1.9 2012/12/16 01:52:05 obache Exp $

PKGNAME=	${DISTNAME:C/-/90-monitoring-/}
PKGREVISION=	1
COMMENT=	PostgreSQL monitoring tools

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS+=		contrib/auto_explain
BUILD_DIRS+=		contrib/pg_buffercache
BUILD_DIRS+=		contrib/pg_stat_statements
BUILD_DIRS+=		contrib/pgstattuple

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
