# $NetBSD: Makefile,v 1.4 2024/05/07 03:50:18 adam Exp $

DISTNAME=	truststore-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/truststore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sethmlarson/truststore
COMMENT=	Verify certificates using native system trust stores
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx-[0-9]*:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver-[0-9]*:../../devel/py-test-httpserver

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
