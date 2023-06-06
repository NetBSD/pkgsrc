# $NetBSD: Makefile,v 1.5 2023/06/06 12:41:50 riastradh Exp $

DISTNAME=	postfix_mta_sts_resolver-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/postfix_mta_sts_resolver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Snawoot/postfix-mta-sts-resolver
COMMENT=	Daemon providing TLS client policy for Postfix based on MTA-STS policy
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pylint>=0:../../devel/py-pylint
TOOL_DEPENDS+=	${PYPKGPREFIX}-tox>=0:../../devel/py-tox
TOOL_DEPENDS+=	${PYPKGPREFIX}-twine>=1.11.0:../../net/py-twine
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.31.0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiodns>=1.1.1:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.4.4:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-aiosqlite>=0.10:../../databases/py-aiosqlite
DEPENDS+=	${PYPKGPREFIX}-redis>=4.2.0:../../databases/py-redis
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.11.0:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.12:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} mta-sts-daemon mta-sts-daemon-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} mta-sts-query mta-sts-query-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography:build
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
