# $NetBSD: Makefile,v 1.3 2021/03/10 18:49:07 adam Exp $

DISTNAME=	blurhash-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blurhash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halcy/blurhash-python
COMMENT=	Implementation of the blurhash algorithm in pure python
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	Pillow test:test

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
