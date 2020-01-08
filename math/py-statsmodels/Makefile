# $NetBSD: Makefile,v 1.6 2020/01/08 01:23:22 minskim Exp $

DISTNAME=	statsmodels-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/statsmodels/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.statsmodels.org/
COMMENT=	Statistical computations and models for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0.24:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.19:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.4.0:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.18:../../math/py-scipy

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-matplotlib, py-scipy
USE_LANGUAGES=			c

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.11
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
