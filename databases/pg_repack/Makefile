# $NetBSD: Makefile,v 1.15 2025/05/06 09:42:44 wiz Exp $

DISTNAME=	pg_repack-1.5.2
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=reorg/}
GITHUB_PROJECT=	pg_repack
GITHUB_TAG=	ver_${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://reorg.github.io/pg_repack/
COMMENT=	Reorganize tables in PostgreSQL databases with minimal locks
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	gmake

PLIST_VARS+=	llvm
.include "../../mk/pgsql.buildlink3.mk"
.if !empty(PKG_OPTIONS.postgresql${PGSQL_VERSION}:Mllvm)
PLIST.llvm=	yes
.endif

.include "../../mk/bsd.pkg.mk"
