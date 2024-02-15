# $NetBSD: Makefile,v 1.20 2024/02/15 22:02:21 wiz Exp $

DISTNAME=	scikit-image-0.19.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-image/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://scikit-image.org/
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.24:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21.4:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.4.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.2:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.1.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-imageio>=2.4.1:../../graphics/py-imageio
DEPENDS+=	${PYPKGPREFIX}-tifffile>=2019.7.26:../../graphics/py-tifffile
DEPENDS+=	${PYPKGPREFIX}-pywavelets>=1.1.1:../../math/py-pywavelets
# optional
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.0.3:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 38
# no python 3.11 support as of 0.19.3
# https://github.com/scikit-image/scikit-image/issues/6598
PYTHON_VERSIONS_INCOMPATIBLE+=	311 312

# Ensure python is fully buildlinked, py-pythran defaults to build only.
PYTHON_FOR_BUILD_ONLY=	no
.include "../../lang/python/pyversion.mk"

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} skivi skivi-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-pythran/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
