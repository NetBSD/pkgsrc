# $NetBSD: Makefile,v 1.4 2025/09/28 19:20:52 wiz Exp $

DISTNAME=	textual_dev-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual_dev/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Textualize/textual-dev
COMMENT=	Development tools for working with Textual
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-textual>=0.36:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.8.1:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.3:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.4:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=0:../../time/py-time-machine
DEPENDS+=	${PYPKGPREFIX}-test-aiohttp>=0:../../www/py-test-aiohttp

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

# as of 1.5.1
# 5 passed, 3 warnings, 18 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
