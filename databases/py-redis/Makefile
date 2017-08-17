# $NetBSD: Makefile,v 1.3 2017/08/17 20:50:37 adam Exp $

DISTNAME=	redis-2.10.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/andymccurdy/redis-py/
COMMENT=	Redis Python client
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.5.0:../../devel/py-test

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
