# $NetBSD: Makefile,v 1.17 2025/03/05 10:09:30 wiz Exp $

DISTNAME=	Wand-0.6.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Wand/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.wand-py.org/
COMMENT=	Ctypes-based simple ImageMagick binding for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

USE_LANGUAGES=	c

WHEEL_NAME=	${DISTNAME:tl}

# 'make test' doesn't work, but running 'pytest' in ${WRKSRC} gives
# 2 failed, 562 passed, 6 skipped, 2 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
