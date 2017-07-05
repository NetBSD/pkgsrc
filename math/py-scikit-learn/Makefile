# $NetBSD: Makefile,v 1.1 2017/07/05 21:31:28 minskim Exp $

DISTNAME=	scikit-learn-0.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-learn/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://scikit-learn.org/
COMMENT=	Machine learning algorithms for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy

USE_LANGUAGES=	c c++ fortran

.include "../../lang/python/egg.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.6.1
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
