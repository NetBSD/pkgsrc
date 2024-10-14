# $NetBSD: Makefile,v 1.23 2024/10/14 06:45:33 wiz Exp $

DISTNAME=	mautrix-0.20.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mautrix/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/tulir/mautrix-python
COMMENT=	Python 3 asyncio Matrix framework
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-attrs>=18.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.5:../../www/py-yarl
TEST_DEPENDS+=	${PYPKGPREFIX}-asyncpg-[0-9]*:../../databases/py-asyncpg
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
TEST_DEPENDS+=	${PYPKGPREFIX}-olm-[0-9]*:../../security/py-olm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-unpaddedbase64-[0-9]*:../../devel/py-unpaddedbase64

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
