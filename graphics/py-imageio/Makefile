# $NetBSD: Makefile,v 1.1 2018/07/31 11:03:57 prlw1 Exp $

DISTNAME=	imageio-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GITHUB:=imageio/}
GITHUB_PROJECT=	imageio
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://imageio.github.io/
COMMENT=	Python library to read and write images
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
