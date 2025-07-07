# $NetBSD: Makefile,v 1.7 2025/07/07 05:58:04 wiz Exp $

DISTNAME=	pytest_examples-0.0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_examples/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/pytest-examples
COMMENT=	Pytest plugin for testing examples in docstrings and markdown files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-black>=23:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-ruff>=0.5.0:../../devel/py-ruff
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
