# $NetBSD: Makefile,v 1.9 2025/07/07 05:58:04 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
