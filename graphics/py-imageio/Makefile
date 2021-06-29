# $NetBSD: Makefile,v 1.6 2021/06/29 08:42:00 nia Exp $

DISTNAME=	imageio-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/imageio/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://imageio.github.io/
COMMENT=	Python library to read and write images
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36	# py-numpy

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC}/imageio/resources && \
	${CHMOD} 644 shipped_resources_go_here images/*

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} imageio_download_bin imageio_download_bin-${PYVERSSUFFIX} && \
	${MV} imageio_remove_bin imageio_remove_bin-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
