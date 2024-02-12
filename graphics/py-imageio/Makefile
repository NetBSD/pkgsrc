# $NetBSD: Makefile,v 1.15 2024/02/12 13:54:38 adam Exp $

DISTNAME=	imageio-2.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/imageio/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://imageio.readthedocs.io/
COMMENT=	Python library to read and write images
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-Pillow>=8.3.2:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-fsspec-[0-9]*:../../sysutils/py-fsspec
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} imageio_download_bin imageio_download_bin-${PYVERSSUFFIX} && \
	${MV} imageio_remove_bin imageio_remove_bin-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
