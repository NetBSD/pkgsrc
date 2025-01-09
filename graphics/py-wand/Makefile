# $NetBSD: Makefile,v 1.16 2025/01/09 08:55:23 wiz Exp $

DISTNAME=	Wand-0.6.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Wand/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.wand-py.org/
COMMENT=	Ctypes-based simple ImageMagick binding for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

USE_LANGUAGES=	c

# 'make test' doesn't work, but running 'pytest' in ${WRKSRC} gives
# 2 failed, 562 passed, 6 skipped, 2 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
