# $NetBSD: Makefile,v 1.2 2016/08/12 09:38:37 fhajny Exp $

DISTNAME=	fast_yaml-1.0.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/fast_yaml/
COMMENT=	Fast YAML native library for Erlang / Elixir
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.5:../../misc/erlang-p1_utils

GITHUB_PROJECT=	fast_yaml

GNU_CONFIGURE=	yes

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
