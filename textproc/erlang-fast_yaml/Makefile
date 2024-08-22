# $NetBSD: Makefile,v 1.15 2024/08/22 05:55:13 adam Exp $

DISTNAME=	fast_yaml-1.0.37
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	fast_yaml

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/fast_yaml
COMMENT=	Fast YAML native library for Erlang / Elixir
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.26:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
