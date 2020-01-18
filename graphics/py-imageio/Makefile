# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:18 rillig Exp $

DISTNAME=	imageio-2.5.0
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

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} imageio_download_bin imageio_download_bin-${PYVERSSUFFIX} && \
	${MV} imageio_remove_bin imageio_remove_bin-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
