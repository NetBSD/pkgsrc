# $NetBSD: Makefile,v 1.1 2022/10/13 16:01:42 adam Exp $

DISTNAME=	contourpy-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/contourpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/contourpy/contourpy
COMMENT=	Python library for calculating contours of 2D quadrilateral grids
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.2.0:../../graphics/py-Pillow
TEST_DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	c c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # py-numpy

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
