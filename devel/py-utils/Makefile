# $NetBSD: Makefile,v 1.12 2023/09/27 09:45:27 adam Exp $

DISTNAME=	python-utils-3.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-utils
COMMENT=	Some convenient utilities not included with standard Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-typing-extensions>3.10.0.2:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-loguru-[0-9]*:../../sysutils/py-loguru
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-[0-9]*:../../devel/py-test-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-types-setuptools-[0-9]*:../../devel/py-types-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} _python_utils_tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
