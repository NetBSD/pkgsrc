# $NetBSD: Makefile,v 1.32 2024/11/01 12:51:44 wiz Exp $

DISTNAME=	sqlite3-1.1.15
PKGREVISION=	2
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
