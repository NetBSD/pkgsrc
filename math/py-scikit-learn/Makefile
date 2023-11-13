# $NetBSD: Makefile,v 1.26 2023/11/13 10:42:42 wiz Exp $

DISTNAME=	scikit-learn-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-learn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scikit-learn.org/
COMMENT=	Machine learning algorithms for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-joblib>=1.1.1:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.5.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-threadpoolctl>=2.0.0:../../parallel/py-threadpoolctl
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.9.0:../../devel/py-test-cov

USE_LANGUAGES=	c c++ fortran

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=3
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.17.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
