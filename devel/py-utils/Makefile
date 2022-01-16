# $NetBSD: Makefile,v 1.7 2022/01/16 08:44:20 adam Exp $

DISTNAME=	python-utils-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-utils
COMMENT=	Some convenient utilities not included with standard Python
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8>=0:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy>=0:../../devel/py-test-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-types-setuptools>=0:../../devel/py-types-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} _python_utils_tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
