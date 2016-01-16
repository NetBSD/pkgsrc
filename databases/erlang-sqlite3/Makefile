# $NetBSD: Makefile,v 1.4 2016/01/16 19:23:19 fhajny Exp $

DISTNAME=	sqlite3-1.1.5
PKGNAME=	erlang-${DISTNAME}.20151221
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=alexeyr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/alexeyr/erlang-sqlite3/
COMMENT=	Sqlite gen_server port for Erlang
LICENSE=	erlang-public-license

GITHUB_PROJECT=	erlang-sqlite3
GITHUB_TAG=	cbc3505f7a131254265d3ef56191b2581b8cc172
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

MAKE_FILE=	GNUmakefile
ERL_MOD_DIR=	lib/erlang/lib/${DISTNAME}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
