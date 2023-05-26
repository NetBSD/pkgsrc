# $NetBSD: Makefile,v 1.22 2023/05/26 19:51:10 adam Exp $

DISTNAME=	pytest-cov-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-cov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-cov
COMMENT=	Pytest plugin for measuring coverage
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-coverage>=5.2.1:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-test>=4.6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-fields-[0-9]*:../../devel/py-fields
TEST_DEPENDS+=	${PYPKGPREFIX}-process-tests-[0-9]*:../../devel/py-process-tests
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs to be installed for testing, this setting is not enoough
# as of 4.0.0:
# 3 failed, 115 passed, 6 skipped, 4 xpassed, 1 warning
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
