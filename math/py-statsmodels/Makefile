# $NetBSD: Makefile,v 1.3 2018/07/05 13:09:11 adam Exp $

DISTNAME=	statsmodels-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/statsmodels/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.statsmodels.org/stable/index.html
COMMENT=	Statistical computations and models for use with SciPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython>=0.14.1:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.14.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.3.0:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
