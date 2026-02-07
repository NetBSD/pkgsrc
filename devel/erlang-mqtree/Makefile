# $NetBSD: Makefile,v 1.5 2026/02/07 00:41:46 gdt Exp $

DISTNAME=	mqtree-1.0.19
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	mqtree

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/mqtree
COMMENT=	Erlang NIF implementation of N-ary tree
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.26:../../misc/erlang-p1_utils

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
