# $NetBSD: Makefile,v 1.15 2026/02/07 00:49:21 gdt Exp $

DISTNAME=	stringprep-1.0.33
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	stringprep

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/stringprep
COMMENT=	Fast Stringprep implementation for Erlang / Elixir
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.26:../../misc/erlang-p1_utils

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
