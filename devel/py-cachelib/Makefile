# $NetBSD: Makefile,v 1.16 2026/05/12 05:26:41 adam Exp $

DISTNAME=	cachelib-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cachelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets/cachelib
COMMENT=	Collection of cache libraries in the same API interface
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=0:../../devel/py-flit_core
TEST_DEPENDS+=	redis-[0-9]*:../../databases/redis
TEST_DEPENDS+=	${PYPKGPREFIX}-redis>=3.5.3:../../databases/py-redis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xprocess>=0.22.2:../../devel/py-test-xprocess
TEST_DEPENDS+=	${PYPKGPREFIX}-uwsgi>=2.0.21:../../www/py-uwsgi

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
