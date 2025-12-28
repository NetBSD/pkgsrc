# $NetBSD: Makefile,v 1.28 2025/12/28 10:27:07 adam Exp $

DISTNAME=	mautrix-0.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mautrix/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/tulir/mautrix-python
COMMENT=	Python 3 asyncio Matrix framework
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-attrs>=18.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.5:../../www/py-yarl
TEST_DEPENDS+=	${PYPKGPREFIX}-aiosqlite-[0-9]*:../../databases/py-aiosqlite
TEST_DEPENDS+=	${PYPKGPREFIX}-asyncpg-[0-9]*:../../databases/py-asyncpg
TEST_DEPENDS+=	${PYPKGPREFIX}-base58-[0-9]*:../../converters/py-base58
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
TEST_DEPENDS+=	${PYPKGPREFIX}-olm-[0-9]*:../../security/py-olm
TEST_DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml-[0-9]*:../../devel/py-ruamel-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64-[0-9]*:../../devel/py-unpaddedbase64

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
