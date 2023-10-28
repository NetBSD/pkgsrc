# $NetBSD: Makefile,v 1.6 2023/10/28 19:57:09 wiz Exp $

DISTNAME=	contourpy-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/contourpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/contourpy/contourpy
COMMENT=	Python library for calculating contours of 2D quadrilateral grids
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python-[0-9]*:../../devel/py-meson_python
# py-matplotlib depends on py-contourpy, but TEST_DEPENDS seems to work fine
TEST_DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	c c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
