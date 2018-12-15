# $NetBSD: Makefile,v 1.4 2018/12/15 21:12:19 wiz Exp $

DISTNAME=	pg_repack-1.4.3
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=reorg/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	http://reorg.github.io/pg_repack/
COMMENT=	Reorganize tables in PostgreSQL databases with minimal locks
LICENSE=	modified-bsd

GITHUB_PROJECT=	pg_repack
GITHUB_TAG=	ver_${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	gmake

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
