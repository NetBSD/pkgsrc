# $NetBSD: Makefile,v 1.22 2026/01/19 08:36:12 adam Exp $

DISTNAME=	arviz-0.23.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arviz/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://python.arviz.org/
COMMENT=	Exploratory analysis of Bayesian models
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-h5netcdf>=1.0.2:../../devel/py-h5netcdf
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.8:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.26.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandas>=2.1.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.11.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.1.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-xarray>=2023.7.0:../../math/py-xarray
DEPENDS+=	${PYPKGPREFIX}-xarray-einstats>=0.3:../../math/py-xarray-einstats
TEST_DEPENDS+=	${PYPKGPREFIX}-cloudpickle-[0-9]*:../../converters/py-cloudpickle
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-xarray-einstats

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
