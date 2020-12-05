# $NetBSD: Makefile,v 1.1 2020/12/05 09:04:58 otis Exp $

WAL2JSONVERSION=	2.3
GITHUB_PROJECT=		wal2json
GITHUB_TAG=		${GITHUB_PROJECT}_${WAL2JSONVERSION:C/\./_/}
DISTNAME=		${GITHUB_PROJECT}_${WAL2JSONVERSION:C/\./_/}
PKGNAME=		postgresql${PGSQL_VERSION}-${GITHUB_PROJECT}-${WAL2JSONVERSION}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_GITHUB:=eulerto/}

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/eulerto/wal2json
COMMENT=	Plugin to decode PostgreSQL WAL to JSON
LICENSE=	modified-bsd

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=	gmake

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
