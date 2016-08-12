# $NetBSD: Makefile,v 1.3 2016/08/12 09:44:20 fhajny Exp $

DISTNAME=	stringprep-1.0.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/stringprep/
COMMENT=	Fast Stringprep implementation for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	stringprep

DEPENDS+=	erlang-p1_utils>=1.0.5:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
