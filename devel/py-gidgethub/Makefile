# $NetBSD: Makefile,v 1.3 2023/10/28 19:57:00 wiz Exp $

DISTNAME=	gidgethub-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gidgethub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/gidgethub/
COMMENT=	Async GitHub API library
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit-[0-9]*:../../devel/py-flit
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=3.0.1:../../textproc/py-uritemplate
DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0.0:../../textproc/py-JWT
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0.16.1:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
# not packaged yet
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-tornasync-[0-9]*:../../devel/py-test-tornasync
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
