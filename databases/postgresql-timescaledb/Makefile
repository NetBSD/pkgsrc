# $NetBSD: Makefile,v 1.28 2024/05/11 05:22:54 adam Exp $

DISTNAME=	timescaledb-2.15.0
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	timescaledb

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb
COMMENT=	The timescaledb extension for PostgreSQL
LICENSE=	apache-2.0

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

CMAKE_ARGS+=	-DUSE_OPENSSL=ON
CMAKE_ARGS+=	-DREGRESS_CHECKS=OFF

.include "../../mk/bsd.prefs.mk"

.if ${SHLIB_TYPE} == "dylib"
PLIST_SUBST+=	SOEXT=dylib
.else
PLIST_SUBST+=	SOEXT=so
.endif

PGSQL_VERSIONS_ACCEPTED=	16 15 14 13

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

.include "../../devel/cmake/build.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
