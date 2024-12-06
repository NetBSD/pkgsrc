# $NetBSD: Makefile,v 1.2 2024/12/06 22:05:31 wiz Exp $

DISTNAME=	textual_dev-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=t/textual_dev/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Textualize/textual-dev
COMMENT=	Development tools for working with Textual
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-textual>=0.36:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.8.1:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.0.3:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.4:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=0:../../time/py-time-machine
DEPENDS+=	${PYPKGPREFIX}-test-aiohttp>=0:../../www/py-test-aiohttp

USE_LANGUAGES=	# none

# as of 1.5.1
# 5 passed, 3 warnings, 18 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
