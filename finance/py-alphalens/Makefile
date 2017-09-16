# $NetBSD: Makefile,v 1.1 2017/09/16 21:31:35 minskim Exp $

DISTNAME=	alphalens-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=quantopian/}
GITHUB_PROJECT=	alphalens
GITHUB_TAG=	v0.1.1

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/quantopian/alphalens/
COMMENT=	Performance analysis of predictive stock factors
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-seaborn-[0-9]*:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-statsmodels-[0-9]*:../../math/py-statsmodels

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
