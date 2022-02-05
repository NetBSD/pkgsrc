# $NetBSD: Makefile,v 1.8 2022/02/05 14:50:00 adam Exp $

DISTNAME=	alphalens-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alphalens/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/alphalens
COMMENT=	Performance analysis of predictive stock factors
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-empyrical>=0.5.0:../../finance/py-empyrical
DEPENDS+=	${PYPKGPREFIX}-ipython>=3.2.3:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=1.4.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.14.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-seaborn>=0.6.0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-statsmodels>=0.6.1:../../math/py-statsmodels

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # py-ipython, py-matplotlib, py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
