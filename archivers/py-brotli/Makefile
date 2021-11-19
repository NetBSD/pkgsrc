# $NetBSD: Makefile,v 1.2 2021/11/19 09:49:42 adam Exp $

DISTNAME=	Brotli-1.0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/brotli/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/brotli
COMMENT=	Generic-purpose lossless compression algorithm (Python module)
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
