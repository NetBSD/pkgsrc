# $NetBSD: Makefile,v 1.32 2026/10/20 06:10:44 adam Exp $

DISTNAME=	astropy-8.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/astropy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.astropy.org/
COMMENT=	Python module for astronomical calculations and data analysis
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.0:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-extension-helpers>=1.4:../../devel/py-extension-helpers
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.0.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-astropy-iers-data>=0.2026.9.28.0.59.37:../../math/py-astropy-iers-data
DEPENDS+=	${PYPKGPREFIX}-pyerfa>=2.0.1.3:../../math/py-pyerfa
DEPENDS+=	${PYPKGPREFIX}-packaging>=25.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.0:../../textproc/py-yaml
# recommended
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.8.4:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-narwhals>=1.42.0:../../misc/py-narwhals
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.13:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.4.4:../../devel/py-coverage
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-astropy>=0.10.0:../../math/py-test-astropy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-astropy-header>=0.2.1:../../devel/py-test-astropy-header
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=1.4.0:../../devel/py-test-doctestplus
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.5.0:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-threadpoolctl>=3.0.0:../../parallel/py-threadpoolctl

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
