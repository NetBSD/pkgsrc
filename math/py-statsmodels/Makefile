# $NetBSD: Makefile,v 1.33 2026/09/04 09:16:49 adam Exp $

DISTNAME=	statsmodels-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/statsmodels/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.statsmodels.org/
COMMENT=	Statistical computations and models for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.13:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=9.2.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-formulaic>=1.1.0:../../math/py-formulaic
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandas>=2.1.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.5.6:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.13.0:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=0:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-run-parallel>=0:../../devel/py-test-run-parallel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist

REPLACE_PYTHON+=	statsmodels/tools/print_version.py
REPLACE_PYTHON+=	statsmodels/tsa/ardl/_pss_critical_values/pss.py
REPLACE_PYTHON+=	statsmodels/tsa/ardl/pss_critical_values.py

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-numpy

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=2.0.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
