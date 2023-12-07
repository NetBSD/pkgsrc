# $NetBSD: Makefile,v 1.7 2023/12/07 18:08:41 wiz Exp $

DISTNAME=	click_aliases-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click_aliases/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/click_aliases/
COMMENT=	Add (mutiple) aliases to a click group or command
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-[0-9]*:../../devel/py-poetry

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_LANGUAGES=	# none

# no tests included
USE_PYTEST=	no

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
