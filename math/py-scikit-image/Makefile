# $NetBSD: Makefile,v 1.21 2024/02/15 22:14:14 wiz Exp $

DISTNAME=	scikit_image-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-image/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://scikit-image.org/
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.32:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.13:../../devel/py-meson_python
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21.1:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.8:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.8:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.0.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-imageio>=2.27:../../graphics/py-imageio
DEPENDS+=	${PYPKGPREFIX}-tifffile>=2022.8.12:../../graphics/py-tifffile
DEPENDS+=	${PYPKGPREFIX}-pywavelets>=1.1.1:../../math/py-pywavelets
DEPENDS+=	${PYPKGPREFIX}-packaging>=21:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-lazy_loader>=0.2:../../misc/py-lazy_loader
# optional
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.0.3:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

pre-configure:
	${LN} -f -s ${PREFIX}/bin/cython-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cython
	${LN} -f -s ${PREFIX}/bin/pythran-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/pythran

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-pythran/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
