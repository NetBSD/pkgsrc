# $NetBSD: Makefile,v 1.30 2026/03/26 14:47:55 wiz Exp $

DISTNAME=	pytest_cov-7.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-cov
COMMENT=	Pytest plugin for measuring coverage
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-coverage>=7.10.6:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.2:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-process-tests-[0-9]*:../../devel/py-process-tests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

USE_LANGUAGES=	# none

# needs to be installed for testing, this setting is not enoough
# as of 7.1.0:
# 1 failed, 205 passed, 3 skipped
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
