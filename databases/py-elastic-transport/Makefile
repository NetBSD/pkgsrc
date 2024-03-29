# $NetBSD: Makefile,v 1.3 2024/01/19 19:57:35 adam Exp $

DISTNAME=	elastic-transport-8.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/elastic-transport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/elastic/elastic-transport-python
COMMENT=	Transport classes and utilities shared among Python Elastic libraries
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26.2:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpserver-[0-9]*:../../devel/py-test-httpserver
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
