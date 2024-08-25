# $NetBSD: Makefile,v 1.34 2024/08/25 06:18:31 wiz Exp $

DISTNAME=	timescaledb-2.16.1
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}
GITHUB_PROJECT=	timescaledb

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb
COMMENT=	The timescaledb extension for PostgreSQL
LICENSE=	apache-2.0

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

CMAKE_CONFIGURE_ARGS+=	-DUSE_OPENSSL=ON
CMAKE_CONFIGURE_ARGS+=	-DREGRESS_CHECKS=OFF

.include "../../mk/bsd.prefs.mk"

.if ${SHLIB_TYPE} == "dylib"
PLIST_SUBST+=	SOEXT=dylib
.else
PLIST_SUBST+=	SOEXT=so
.endif

PGSQL_VERSIONS_ACCEPTED=	16 15 14

PKG_OPTIONS_VAR=		PKG_OPTIONS.timescaledb
PKG_SUPPORTED_OPTIONS+=		timescale-license
PKG_SUGGESTED_OPTIONS+=		timescale-license

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		tsl
.if !empty(PKG_OPTIONS:Mtimescale-license)
LICENSE+=		AND timescale-license
CMAKE_CONFIGURE_ARGS+=		-DAPACHE_ONLY=OFF
RESTRICTED=		No clear permission granted to distribute
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
PLIST.tsl=		yes
.else
CMAKE_CONFIGURE_ARGS+=		-DAPACHE_ONLY=ON
.endif

.include "../../devel/cmake/build.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
