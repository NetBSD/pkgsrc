# $NetBSD: Makefile,v 1.3 2022/10/14 16:50:37 triaxx Exp $

DISTNAME=	mqtree-1.0.15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/mqtree
COMMENT=	Erlang NIF implementation of N-ary tree
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.25:../../misc/erlang-p1_utils

GITHUB_PROJECT=	mqtree

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
