# $NetBSD: Makefile,v 1.14 2021/04/20 21:48:14 thor Exp $

DISTNAME=	scikit-learn-0.22.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-learn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scikit-learn.org/
COMMENT=	Machine learning algorithms for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-joblib>=0.11:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.17.0:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

# XXX: OpenMP is not portable
MAKE_ENV+=	SKLEARN_NO_OPENMP=1

USE_LANGUAGES=	c c++ fortran

PYTHON_VERSIONS_INCOMPATIBLE=	36 27	# py-scipy

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.11.0
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
