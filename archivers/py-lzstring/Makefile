# $NetBSD: Makefile,v 1.2 2023/07/24 04:51:37 adam Exp $

DISTNAME=	lzstring-1.0.4
PKGNAME=	${PYPKGPREFIX}-lzstring-1.0.4
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lzstring/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/gkovacs/lz-string-python
COMMENT=	LZ-based in-memory string compression
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-future>=0.14.0:../../devel/py-future

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
