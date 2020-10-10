# $NetBSD: Makefile,v 1.2 2020/10/10 11:20:10 mef Exp $

GITHUB_PROJECT=	timescaledb
DISTNAME=	timescaledb-1.7.4
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=timescale/}

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/timescale/timescaledb/
COMMENT=	The timescaledb extension for PostgreSQL
LICENSE=	apache-2.0

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=	cmake gmake bash

CONFIGURE_ARGS+=	-DUSE_OPENSSL=0
CONFIGURE_ARGS+=	-DREGRESS_CHECKS=OFF

.include "../../mk/bsd.prefs.mk"

do-configure:
	cd ${WRKSRC} && \
	   ${SETENV} ${CONFIGURE_ENV} ./bootstrap ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC}/build && \
	   ${SETENV} ${MAKE_ENV} \
	   ${MAKE} DESTDIR=${DESTDIR} PREFIX=${PREFIX}

do-install:
	cd ${WRKSRC}/build && \
	   ${SETENV} ${INSTALL_ENV} \
	   ${MAKE} DESTDIR=${DESTDIR} PREFIX=${PREFIX} install

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
