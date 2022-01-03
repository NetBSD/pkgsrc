# $NetBSD: Makefile,v 1.5 2022/01/03 07:43:22 adam Exp $

DISTNAME=	cachelib-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cachelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets/cachelib
COMMENT=	Collection of cache libraries in the same API interface
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-redis>=3.5.3:../../databases/py-redis
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xprocess>=0.17.1:../../devel/py-test-xprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-uwsgi>=2.0.19.1:../../www/py-uwsgi

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
