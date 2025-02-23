# $NetBSD: Makefile,v 1.20 2025/02/23 18:34:40 wiz Exp $

DISTNAME=	blinker-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blinker/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://blinker.readthedocs.io/
COMMENT=	Fast, simple object-to-object and broadcast signaling
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# empty

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
