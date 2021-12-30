# $NetBSD: Makefile,v 1.10 2021/12/30 13:05:39 adam Exp $

DISTNAME=	statsmodels-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/statsmodels/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.statsmodels.org/
COMMENT=	Statistical computations and models for Python
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-scipy
USE_LANGUAGES=			c

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.21:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-patsy>=0.5:../../math/py-patsy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.1:../../math/py-scipy

post-extract:
	${CHMOD} -R o-w,g-w ${WRKSRC}
	${FIND} ${WRKSRC} -type f -printx | ${XARGS} ${CHMOD} a-x

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.15
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
