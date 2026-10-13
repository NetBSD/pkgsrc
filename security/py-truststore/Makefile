# $NetBSD: Makefile,v 1.13 2026/10/13 12:58:23 adam Exp $

DISTNAME=	truststore-0.10.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/truststore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sethmlarson/truststore
COMMENT=	Verify certificates using native system trust stores
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp>=0:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0:../../security/py-trustme
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver>=0:../../devel/py-test-httpserver

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
