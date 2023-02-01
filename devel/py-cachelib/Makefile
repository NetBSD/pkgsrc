# $NetBSD: Makefile,v 1.10 2023/02/01 09:12:04 adam Exp $

DISTNAME=	cachelib-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cachelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets/cachelib
COMMENT=	Collection of cache libraries in the same API interface
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-redis>=3.5.3:../../databases/py-redis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xprocess>=0.22.2:../../devel/py-test-xprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-uwsgi>=2.0.21:../../www/py-uwsgi

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
