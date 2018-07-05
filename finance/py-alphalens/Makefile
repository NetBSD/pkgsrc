# $NetBSD: Makefile,v 1.3 2018/07/05 09:21:29 minskim Exp $

DISTNAME=	alphalens-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=quantopian/}
GITHUB_PROJECT=	alphalens
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/alphalens/
COMMENT=	Performance analysis of predictive stock factors
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-ipython>=3.2.3:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=1.4.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.18.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.14.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-seaborn>=0.6.0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-statsmodels>=0.6.1:../../math/py-statsmodels

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
