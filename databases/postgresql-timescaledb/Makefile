# $NetBSD: Makefile,v 1.7 2021/04/25 10:07:42 tnn Exp $

DISTNAME=	timescaledb-2.2.0
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

PGSQL_VERSIONS_ACCEPTED=	13 12 11

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
