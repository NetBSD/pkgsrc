# $NetBSD: Makefile,v 1.5 2023/08/24 20:08:40 wiz Exp $

DISTNAME=	pyproject_api-1.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyproject_api/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/pyproject-api
COMMENT=	API to interact with the python pyproject.toml based projects
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.17.1:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.1:../../devel/py-packaging
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.2.2:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.3.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.10:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.40:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
.endif

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
