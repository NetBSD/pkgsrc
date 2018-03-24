# $NetBSD: Makefile,v 1.9 2018/03/24 16:36:18 fhajny Exp $

DISTNAME=	stringprep-1.0.11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/stringprep/
COMMENT=	Fast Stringprep implementation for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	stringprep

DEPENDS+=	erlang-p1_utils>=1.0.11:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
