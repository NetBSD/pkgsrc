# $NetBSD: Makefile,v 1.12 2022/10/15 12:13:15 triaxx Exp $

DISTNAME=	stringprep-1.0.29
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/stringprep/
COMMENT=	Fast Stringprep implementation for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	stringprep

DEPENDS+=	erlang-p1_utils>=1.0.25:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
