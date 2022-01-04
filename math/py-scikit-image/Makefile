# $NetBSD: Makefile,v 1.12 2022/01/04 20:54:16 wiz Exp $

DISTNAME=	scikit-image-0.18.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-image/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://scikit-image.org/
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.21:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-numpy>=0.19.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.0.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4.3.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-imageio>=2.3.0:../../graphics/py-imageio
DEPENDS+=	${PYPKGPREFIX}-tifffile>=2021.2.1:../../graphics/py-tifffile
DEPENDS+=	${PYPKGPREFIX}-pywavelets>=0.4.0:../../math/py-pywavelets
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.0:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-tifffile

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} skivi skivi-${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
