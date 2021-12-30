# $NetBSD: Makefile,v 1.7 2021/12/30 13:05:33 adam Exp $

DISTNAME=	ggplot-0.11.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/ggplot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yhat/ggplot
COMMENT=	Python implementation of the grammar of graphics
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-brewer2mpl-[0-9]*:../../graphics/py-brewer2mpl
DEPENDS+=	${PYPKGPREFIX}-cycler-[0-9]*:../../graphics/py-cycler
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas-[0-9]*:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy-[0-9]*:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-statsmodels-[0-9]*:../../math/py-statsmodels
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
# self tests fail in ggplot.aes.aes, see
# https://github.com/yhat/ggplot/issues/507

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-statsmodels py-pandas

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
