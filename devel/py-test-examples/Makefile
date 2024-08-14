# $NetBSD: Makefile,v 1.2 2024/08/14 09:07:28 adam Exp $

DISTNAME=	pytest_examples-0.0.13
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

SUBST_CLASSES+=		ruffpath
SUBST_STAGE.ruffpath=	pre-configure
SUBST_MESSAGE.ruffpath=	Fixing path to ruff.
SUBST_FILES.ruffpath=	pytest_examples/lint.py
SUBST_SED.ruffpath=	-e "s,args = 'ruff',args = 'ruff-${PYVERSSUFFIX}',"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
