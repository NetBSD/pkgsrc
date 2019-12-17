# $NetBSD: Makefile,v 1.1 2019/12/17 10:15:37 leot Exp $

DISTNAME=	Brotli-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotli/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	py-brotli

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/brotli
COMMENT=	Generic-purpose lossless compression algorithm (Python module)
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
