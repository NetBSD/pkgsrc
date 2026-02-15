# $NetBSD: Makefile,v 1.36 2026/02/15 18:22:31 gdt Exp $

DISTNAME=	sqlite3-1.1.15
PKGREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	erlang-sqlite3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/erlang-sqlite3
COMMENT=	Sqlite gen_server port for Erlang
LICENSE=	erlang-public-license

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_FILE=	GNUmakefile

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
