# $NetBSD: Makefile,v 1.5 2017/03/30 14:27:43 fhajny Exp $

DISTNAME=	fast_yaml-1.0.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/fast_yaml/
COMMENT=	Fast YAML native library for Erlang / Elixir
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.7:../../misc/erlang-p1_utils

GITHUB_PROJECT=	fast_yaml

GNU_CONFIGURE=	yes

MAKE_ENV+=	USE_GLOBAL_DEPS=true

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
