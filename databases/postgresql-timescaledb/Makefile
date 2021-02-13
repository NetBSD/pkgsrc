# $NetBSD: Makefile,v 1.5 2021/02/13 15:16:04 gdt Exp $

DISTNAME=	timescaledb-2.0.1
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	timescaledb

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb
COMMENT=	The timescaledb extension for PostgreSQL
LICENSE=	apache-2.0 AND timescale-license

RESTRICTED=		No clear permission granted to distribute
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

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
