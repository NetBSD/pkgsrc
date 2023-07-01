# $NetBSD: Makefile,v 1.5 2023/07/01 08:37:36 wiz Exp $

DISTNAME=	blurhash-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blurhash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halcy/blurhash-python
COMMENT=	Implementation of the blurhash algorithm in pure python
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	Pillow test:test

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
