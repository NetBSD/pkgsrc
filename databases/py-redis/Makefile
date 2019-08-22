# $NetBSD: Makefile,v 1.9 2019/08/22 12:00:46 adam Exp $

DISTNAME=	redis-3.3.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andymccurdy/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

# testing requires a running redis-server
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.5.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
