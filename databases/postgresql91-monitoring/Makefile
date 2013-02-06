# $NetBSD: Makefile,v 1.6 2013/02/06 23:21:59 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/91-monitoring-/}
PKGREVISION=	2
COMMENT=	PostgreSQL monitoring tools

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS+=		contrib/auto_explain
BUILD_DIRS+=		contrib/pg_buffercache
BUILD_DIRS+=		contrib/pg_stat_statements
BUILD_DIRS+=		contrib/pgstattuple

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
