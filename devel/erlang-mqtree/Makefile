# $NetBSD: Makefile,v 1.2 2021/05/20 19:46:24 triaxx Exp $

DISTNAME=	mqtree-1.0.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/mqtree
COMMENT=	Erlang NIF implementation of N-ary tree
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.21:../../misc/erlang-p1_utils

GITHUB_PROJECT=	mqtree

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
