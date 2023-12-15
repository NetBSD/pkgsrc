# $NetBSD: Makefile,v 1.19 2023/12/15 09:48:02 adam Exp $

DISTNAME=	statsmodels-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/statsmodels/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.statsmodels.org/
COMMENT=	Statistical computations and models for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.28:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.21:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.5.2:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.9.3:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly-[0-9]*:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.18
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
