# $NetBSD: Makefile,v 1.11 2026/10/22 16:31:42 adam Exp $

DISTNAME=	brotli-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotli/}
# distfile is distinct from brotli's but filename differs only by case
DIST_SUBDIR=	py-brotli

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/brotli
COMMENT=	Generic-purpose lossless compression algorithm (Python module)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pkgconfig>=0:../../devel/py-pkgconfig
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	c c++

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
