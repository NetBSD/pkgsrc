# $NetBSD: Makefile,v 1.12 2025/10/09 08:01:58 wiz Exp $

DISTNAME=	truststore-0.10.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/truststore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sethmlarson/truststore
COMMENT=	Verify certificates using native system trust stores
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx-[0-9]*:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver-[0-9]*:../../devel/py-test-httpserver

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
