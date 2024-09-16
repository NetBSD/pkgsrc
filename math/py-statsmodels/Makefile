# $NetBSD: Makefile,v 1.23 2024/09/16 19:25:59 adam Exp $

DISTNAME=	statsmodels-0.14.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/statsmodels/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.statsmodels.org/
COMMENT=	Statistical computations and models for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.33:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=69.0.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandas>=2.1.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.5.6:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.13.0:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly-[0-9]*:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	38 39

.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.18
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
