# $NetBSD: Makefile,v 1.9 2021/07/25 16:45:55 tnn Exp $

DISTNAME=	timescaledb-2.3.1
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	timescaledb

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb
COMMENT=	The timescaledb extension for PostgreSQL
LICENSE=	apache-2.0

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_CMAKE=	yes
CMAKE_ARGS+=	-DUSE_OPENSSL=ON
CMAKE_ARGS+=	-DREGRESS_CHECKS=OFF

PGSQL_VERSIONS_ACCEPTED=	13 12 11

PKG_OPTIONS_VAR=		PKG_OPTIONS.timescaledb
PKG_SUPPORTED_OPTIONS+=		timescale-license
PKG_SUGGESTED_OPTIONS+=		timescale-license

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		tsl
.if !empty(PKG_OPTIONS:Mtimescale-license)
LICENSE+=		AND timescale-license
CMAKE_ARGS+=		-DAPACHE_ONLY=OFF
RESTRICTED=		No clear permission granted to distribute
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
PLIST.tsl=		yes
.else
CMAKE_ARGS+=		-DAPACHE_ONLY=ON
.endif

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
