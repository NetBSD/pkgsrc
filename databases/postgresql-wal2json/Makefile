# $NetBSD: Makefile,v 1.2 2022/12/11 09:27:44 wiz Exp $

DISTNAME=		wal2json-2.5
PKGNAME=		postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_GITHUB:=eulerto/}
GITHUB_PROJECT=		wal2json
GITHUB_TAG=		${GITHUB_PROJECT}_${PKGVERSION_NOREV:C/\./_/}

MAINTAINER=	otis@NetBSD.org
HOMEPAGE=	https://github.com/eulerto/wal2json
COMMENT=	Plugin to decode PostgreSQL WAL to JSON
LICENSE=	modified-bsd

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=	gmake

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
