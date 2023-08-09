# $NetBSD: Makefile,v 1.6 2023/08/09 13:10:15 adam Exp $

DISTNAME=	postfix_mta_sts_resolver-1.4.0
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
DEPENDS+=	${PYPKGPREFIX}-asyncpg>=0.27:../../databases/py-asyncpg
DEPENDS+=	${PYPKGPREFIX}-redis>=4.2.0:../../databases/py-redis
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.11.0:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.12:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=0:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in mta-sts-daemon mta-sts-query
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

# No such file or directory: '${WRKSRC}/tests/refdata.tsv'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography:test
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
