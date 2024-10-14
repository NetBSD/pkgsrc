# $NetBSD: Makefile,v 1.8 2024/10/14 06:45:34 wiz Exp $

DISTNAME=	click_aliases-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click_aliases/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/click_aliases/
COMMENT=	Add (mutiple) aliases to a click group or command
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-[0-9]*:../../devel/py-poetry

USE_LANGUAGES=	# none

# no tests included
USE_PYTEST=	no

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
