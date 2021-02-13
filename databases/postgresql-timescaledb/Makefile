# $NetBSD: Makefile,v 1.4 2021/02/13 11:32:35 tnn Exp $

DISTNAME=	timescaledb-2.0.1
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	timescaledb

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb
COMMENT=	The timescaledb extension for PostgreSQL
LICENSE=	apache-2.0 AND timescale-license

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_CMAKE=	yes
CMAKE_ARGS+=	-DUSE_OPENSSL=ON
CMAKE_ARGS+=	-DREGRESS_CHECKS=OFF

PGSQL_VERSIONS_ACCEPTED=	12 11

## This transform can be removed in the next version update
# https://github.com/timescale/timescaledb/commit/63a66524dd8638516d382ed0efc60c75fb17250e
# https://github.com/timescale/timescaledb/commit/2bf69fd4ca2da6a66a8d18642029df4e217a6e99
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
