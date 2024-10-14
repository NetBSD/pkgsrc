# $NetBSD: Makefile,v 1.15 2024/10/14 06:45:48 wiz Exp $

DISTNAME=	arviz-0.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arviz/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://python.arviz.org/
COMMENT=	Exploratory analysis of Bayesian models
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-dm-tree>=0.1.8:../../devel/py-dm-tree
DEPENDS+=	${PYPKGPREFIX}-h5netcdf>=1.0.2:../../devel/py-h5netcdf
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.5:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.23.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandas>=1.5.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.9.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-setuptools>=60.0.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.1.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-xarray>=2022.6.0:../../math/py-xarray
DEPENDS+=	${PYPKGPREFIX}-xarray-einstats>=0.3:../../math/py-xarray-einstats
TEST_DEPENDS+=	${PYPKGPREFIX}-cloudpickle-[0-9]*:../../converters/py-cloudpickle
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
