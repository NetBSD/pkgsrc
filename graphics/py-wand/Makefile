# $NetBSD: Makefile,v 1.13 2023/01/23 00:01:06 wiz Exp $

DISTNAME=	Wand-0.6.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Wand/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.wand-py.org/
COMMENT=	Ctypes-based simple ImageMagick binding for Python
LICENSE=	mit

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
