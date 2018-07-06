# $NetBSD: Makefile,v 1.1 2018/07/06 03:54:01 minskim Exp $

DISTNAME=	pyfolio-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfolio/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/pyfolio
COMMENT=	Performance and risk analysis of financial portfolios
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-empyrical-[0-9]*:../../finance/py-empyrical
DEPENDS+=	${PYPKGPREFIX}-ipython-[0-9]*:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-pymc3-[0-9]*:../../math/py-pymc3
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-scikit-learn-[0-9]*:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-seaborn-[0-9]*:../../graphics/py-seaborn

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
