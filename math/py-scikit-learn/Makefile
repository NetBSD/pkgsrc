# $NetBSD: Makefile,v 1.8 2019/06/17 15:01:45 adam Exp $

DISTNAME=	scikit-learn-0.21.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-learn/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	http://scikit-learn.org/
COMMENT=	Machine learning algorithms for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-joblib>=0.11:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

# XXX: OpenMP is not portable
MAKE_ENV+=	SKLEARN_NO_OPENMP=1

USE_LANGUAGES=	c c++ fortran

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.if !exists(/System/Library/Frameworks/Accelerate.framework)
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.endif
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.11.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
