# $NetBSD: Makefile,v 1.7 2020/05/27 19:37:38 wiz Exp $

DISTNAME=	pg_repack-1.4.3
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=reorg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://reorg.github.io/pg_repack/
COMMENT=	Reorganize tables in PostgreSQL databases with minimal locks
LICENSE=	modified-bsd

PGSQL_VERSIONS_ACCEPTED?=	10 96 95 94

GITHUB_PROJECT=	pg_repack
GITHUB_TAG=	ver_${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	gmake

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
