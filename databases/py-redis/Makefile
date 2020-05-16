# $NetBSD: Makefile,v 1.17 2020/05/16 09:03:22 adam Exp $

DISTNAME=	redis-3.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/redis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andymccurdy/redis-py
COMMENT=	Redis Python client
LICENSE=	mit

# testing requires a running redis-server
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
