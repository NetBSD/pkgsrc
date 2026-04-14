# $NetBSD: Makefile,v 1.43 2026/04/14 13:28:17 adam Exp $

DISTNAME=	xarray-2026.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xarray/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/pydata/xarray
COMMENT=	N-D labeled arrays and datasets in Python
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.26:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandas>=2.2:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-cftime>0:../../time/py-cftime
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-env>0:../../devel/py-test-env
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-plugins>=4.0.0:../../devel/py-test-mypy-plugins
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
