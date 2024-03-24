# $NetBSD: Makefile,v 1.25 2024/03/24 19:24:42 adam Exp $

DISTNAME=	importlib_resources-6.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib_resources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-resources.readthedocs.io/
COMMENT=	Read resources from Python packages
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.test>=5.4:../../devel/py-jaraco.test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-checkdocs>=2.4:../../devel/py-test-checkdocs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-[0-9]*:../../devel/py-test-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-zipp>=3.17:../../archivers/py-zipp

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-zipp>=3.1.0:../../archivers/py-zipp
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
