# $NetBSD: Makefile,v 1.3 2013/02/06 23:22:01 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/92-monitoring-/}
PKGREVISION=	2
COMMENT=	PostgreSQL monitoring tools

DEPENDS+=	postgresql92-server>=${PKGVERSION_NOREV}:../../databases/postgresql92-server

.include "../../databases/postgresql92/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS+=		contrib/auto_explain
BUILD_DIRS+=		contrib/pg_buffercache
BUILD_DIRS+=		contrib/pg_stat_statements
BUILD_DIRS+=		contrib/pgstattuple

.include "../../databases/postgresql92-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
