# $NetBSD: Makefile,v 1.1 2020/03/05 20:36:44 nia Exp $

DISTNAME=	blurhash-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blurhash/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halcy/blurhash-python
COMMENT=	Implementation of the blurhash algorithm in pure python
LICENSE=	mit

USE_LANGUAGES=	# none

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
