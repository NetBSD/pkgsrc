# $NetBSD: Makefile,v 1.7 2024/09/05 07:44:40 adam Exp $

DISTNAME=	mocket-3.12.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mocket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mindflayer/python-mocket
COMMENT=	Socket Mock Framework
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.22.2:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4.5:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.3:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-h11>0:../../www/py-h11
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp>0:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-asgiref>0:../../www/py-asgiref
TEST_DEPENDS+=	${PYPKGPREFIX}-gevent>0:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>0:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-pook>0:../../www/py-pook
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>0:../../sysutils/py-psutil
# needs redis server as well
TEST_DEPENDS+=	${PYPKGPREFIX}-redis>0:../../databases/py-redis
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-sure>0:../../devel/py-sure

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
