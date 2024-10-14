# $NetBSD: Makefile,v 1.30 2024/10/14 06:45:52 wiz Exp $

DISTNAME=	scikit_learn-1.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-learn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scikit-learn.org/
COMMENT=	Machine learning algorithms for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	meson>=1.1.0:../../devel/meson
TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.16.0:../../devel/py-meson_python
DEPENDS+=	${PYPKGPREFIX}-joblib>=1.2.0:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6.0:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-threadpoolctl>=3.1.0:../../parallel/py-threadpoolctl
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.9.0:../../devel/py-test-cov

USE_LANGUAGES=	c c++ fortran
USE_TOOLS+=	pkg-config
GCC_REQD+=	8

REPLACE_PYTHON+=	sklearn/_build_utils/version.py

PYTHON_VERSIONS_INCOMPATIBLE=	39

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/sklearn/preprocessing/_target_encoder_fast.pyx.orig
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/sklearn/tree/_tree.pyx.orig

do-test:
	cd ${DESTDIR}${PREFIX}/${PYSITELIB}/sklearn && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=3
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.19.5
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
