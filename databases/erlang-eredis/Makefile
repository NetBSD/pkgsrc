# $NetBSD: Makefile,v 1.5 2022/10/15 17:49:34 triaxx Exp $

DISTNAME=	eredis-1.2.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=wooga/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wooga/eredis/
COMMENT=	Erlang Redis client
LICENSE=	mit

GITHUB_PROJECT=	eredis
GITHUB_TAG=	v${PKGVERSION_NOREV}

ERL_MOD_DIR=	lib/erlang/lib/${DISTNAME}

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
