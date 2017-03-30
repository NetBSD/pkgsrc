# $NetBSD: Makefile,v 1.5 2017/03/30 14:26:17 fhajny Exp $

DISTNAME=	stringprep-1.0.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/stringprep/
COMMENT=	Fast Stringprep implementation for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	stringprep

DEPENDS+=	erlang-p1_utils>=1.0.7:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

MAKE_ENV+=	USE_GLOBAL_DEPS=true

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
