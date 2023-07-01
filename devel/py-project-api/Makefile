# $NetBSD: Makefile,v 1.2 2023/07/01 11:25:04 wiz Exp $

DISTNAME=	pyproject_api-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyproject_api/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pyproject-api/
COMMENT=	API to interact with the python pyproject.toml based projects
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-packaging>=23:../../devel/py-packaging
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.2.2:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.10:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.17.1:../../devel/py-virtualenv
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-packaging>=23:../../devel/py-packaging
.endif
.if ${PYTHON_VERSION} < 308
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=6:../../devel/py-importlib-metadata
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
