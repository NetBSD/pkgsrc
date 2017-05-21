# $NetBSD: Makefile,v 1.2 2017/05/21 09:07:37 adam Exp $

DISTNAME=	statsmodels-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/statsmodels/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://statsmodels.sourceforge.net/
COMMENT=	Statistical computations and models for use with SciPy
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cython>=0.14.1:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.14.1:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.3.0:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
