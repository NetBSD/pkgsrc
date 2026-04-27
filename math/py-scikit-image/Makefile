# $NetBSD: Makefile,v 1.30 2026/04/27 10:01:18 wiz Exp $

DISTNAME=	scikit_image-0.26.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-image/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://scikit-image.org/
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.16:../../devel/py-meson_python
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10.1:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-imageio>=2.36:../../graphics/py-imageio
DEPENDS+=	${PYPKGPREFIX}-lazy_loader>=0.4:../../misc/py-lazy_loader
DEPENDS+=	${PYPKGPREFIX}-networkx>=3.0:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.24:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-packaging>=21:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.11.4:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-tifffile>=2022.8.12:../../graphics/py-tifffile
# optional
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.7:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pywavelets>=1.6:../../math/py-pywavelets

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GCC_REQD+=	9

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-tifffile

pre-configure:
	${LN} -f -s ${PREFIX}/bin/cython-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cython
	${LN} -f -s ${PREFIX}/bin/pythran-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/pythran

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/py-pythran/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
