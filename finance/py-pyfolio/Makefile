# $NetBSD: Makefile,v 1.6 2022/02/05 11:45:50 adam Exp $

DISTNAME=	pyfolio-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfolio/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/pyfolio
COMMENT=	Performance and risk analysis of financial portfolios
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-empyrical>=0.5.0:../../finance/py-empyrical
DEPENDS+=	${PYPKGPREFIX}-ipython>=3.2.3:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=1.4.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.11.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-pymc3>=3.5:../../math/py-pymc3
DEPENDS+=	${PYPKGPREFIX}-pytz>=2014.10:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.16.1:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.14.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-seaborn>=0.7.1:../../graphics/py-seaborn
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
#TEST_DEPENDS+=	${PYPKGPREFIX}-nose-parameterized>=0.5.0
#TEST_DEPENDS+=	${PYPKGPREFIX}-runipy>=0.1.3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # py-ipython, py-matplotlib, py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
