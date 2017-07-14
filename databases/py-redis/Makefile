# $NetBSD: Makefile,v 1.1 2017/07/14 11:36:27 adam Exp $

DISTNAME=	redis-2.10.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/andymccurdy/redis-py/
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	redis-[0-9]*:../../databases/redis
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.5.0:../../devel/py-test

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
