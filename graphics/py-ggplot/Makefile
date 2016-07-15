# $NetBSD: Makefile,v 1.2 2016/07/15 07:37:26 wiz Exp $

DISTNAME=	ggplot-0.10.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/ggplot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://yhat.github.io/ggplot/
COMMENT=	Python implementation of the grammar of graphics
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-brewer2mpl-[0-9]*:../../graphics/py-brewer2mpl
DEPENDS+=	${PYPKGPREFIX}-cycler-[0-9]*:../../devel/py-cycler
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy-[0-9]*:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-statsmodels-[0-9]*:../../math/py-statsmodels
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
# self tests fail in ggplot.aes.aes, see
# https://github.com/yhat/ggplot/issues/507

USE_LANGUAGES=	c

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
