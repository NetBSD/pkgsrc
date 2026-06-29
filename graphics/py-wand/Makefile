# $NetBSD: Makefile,v 1.21 2026/06/29 11:28:41 adam Exp $

DISTNAME=	wand-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Wand/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.wand-py.org/
COMMENT=	Ctypes-based simple ImageMagick binding for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

# 'make test' doesn't work, but running 'pytest' in ${WRKSRC} gives
# 2 failed, 562 passed, 6 skipped, 2 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
