# $NetBSD: Makefile,v 1.4 2018/03/08 19:39:17 minskim Exp $

DISTNAME=	scikit-learn-0.19.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-learn/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://scikit-learn.org/
COMMENT=	Machine learning algorithms for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.0:../../math/py-scipy

USE_LANGUAGES=	c c++ fortran

.include "../../lang/python/egg.mk"
.if !exists(/System/Library/Frameworks/Accelerate.framework)
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.8.2
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
