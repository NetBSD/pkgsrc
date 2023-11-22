# $NetBSD: Makefile,v 1.6 2023/11/22 18:32:47 schmonz Exp $

DISTNAME=	Brotli-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotli/}
# distfile is distinct from brotli's but filename differs only by case
DIST_SUBDIR=	py-brotli

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/brotli
COMMENT=	Generic-purpose lossless compression algorithm (Python module)
LICENSE=	mit

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
