# $NetBSD: Makefile,v 1.97 2026/04/15 17:33:10 wiz Exp $

DISTNAME=	google_auth-2.49.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google_auth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-cloud-python/tree/main/packages/google-auth
COMMENT=	Google Authentication Library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.2.1:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-rsa>=3.1.4:../../security/py-rsa
# pyjwt
DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0:../../textproc/py-JWT
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.6.2:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-aioresponses-[0-9]*:../../net/py-aioresponses
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-grpcio-[0-9]*:../../net/py-grpcio
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-oauth2client-[0-9]*:../../security/py-oauth2client
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver
TEST_DEPENDS+=	${PYPKGPREFIX}-u2f>=0.1.5:../../security/py-u2f
TEST_DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3

USE_LANGUAGES=	# none

# as of 2.49.2
# 1 failed, 1574 passed, 17 skipped, 90 warnings
.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
