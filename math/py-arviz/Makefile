# $NetBSD: Makefile,v 1.1 2019/11/25 04:08:33 minskim Exp $

DISTNAME=	arviz-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arviz/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://github.com/arviz-devs/arviz
COMMENT=	Exploratory analysis of Bayesian models
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-netCDF4-[0-9]*:../../math/py-netCDF4
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.12:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.23:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.19:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-xarray>=0.11:../../math/py-xarray

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-pandas

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
