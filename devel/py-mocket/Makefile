# $NetBSD: Makefile,v 1.1 2022/08/24 12:52:40 wiz Exp $

DISTNAME=	mocket-3.10.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mocket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mindflayer/python-mocket
COMMENT=	Socket Mock Framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-magic>=0.4.5:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.3:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-http-parser>=0.9.0:../../www/py-http-parser
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp>=0:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
# needs redis server as well
#TEST_DEPENDS+=	${PYPKGPREFIX}-redis>=0:../../databases/py-redis
TEST_DEPENDS+=	${PYPKGPREFIX}-gevent>=0:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-sure>=0:../../devel/py-sure
TEST_DEPENDS+=	${PYPKGPREFIX}-pook>=0:../../www/py-pook

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
