# $NetBSD: Makefile,v 1.14 2026/08/05 02:48:52 adam Exp $

DISTNAME=	postfix_mta_sts_resolver-1.5.1
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/postfix_mta_sts_resolver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Snawoot/postfix-mta-sts-resolver
COMMENT=	Daemon providing TLS client policy for Postfix based on MTA-STS policy
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiodns>=1.1.1:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.4.4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.12:../../textproc/py-yaml
# sqlite
DEPENDS+=	${PYPKGPREFIX}-aiosqlite>=0.10:../../databases/py-aiosqlite
# postgres
DEPENDS+=	${PYPKGPREFIX}-asyncpg>=0.27:../../databases/py-asyncpg
# redis
DEPENDS+=	${PYPKGPREFIX}-redis>=4.2.0:../../databases/py-redis
# uvloop
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.11.0:../../devel/py-uvloop
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	mta-sts-daemon mta-sts-query

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography:test
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
