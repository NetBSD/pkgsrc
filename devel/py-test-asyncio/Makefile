# $NetBSD: Makefile,v 1.24 2023/10/28 19:57:06 wiz Exp $

DISTNAME=	pytest-asyncio-0.21.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-asyncio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-asyncio
COMMENT=	Pytest support for asyncio
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.36:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.7.1:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.5.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.931:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-trio>=0.7.0:../../devel/py-test-trio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# package needs to be installed before testing, next line is not enough
#TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
