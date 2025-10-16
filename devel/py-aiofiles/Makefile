# $NetBSD: Makefile,v 1.15 2025/10/16 09:42:34 adam Exp $

DISTNAME=	aiofiles-25.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiofiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Tinche/aiofiles
COMMENT=	File support for asyncio
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=1.0.0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
