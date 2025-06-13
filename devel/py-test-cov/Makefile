# $NetBSD: Makefile,v 1.27 2025/06/13 09:03:53 adam Exp $

DISTNAME=	pytest_cov-6.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-cov
COMMENT=	Pytest plugin for measuring coverage
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-coverage>=7.5:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.2:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-test>=6.2.5:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-fields-[0-9]*:../../devel/py-fields
TEST_DEPENDS+=	${PYPKGPREFIX}-process-tests-[0-9]*:../../devel/py-process-tests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv

USE_LANGUAGES=	# none

# needs to be installed for testing, this setting is not enoough
# as of 4.0.0:
# 3 failed, 115 passed, 6 skipped, 4 xpassed, 1 warning
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
