# $NetBSD: Makefile,v 1.18 2024/05/12 10:36:33 wiz Exp $

DISTNAME=	blinker-1.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blinker/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://blinker.readthedocs.io/
COMMENT=	Fast, simple object-to-object and broadcast signaling
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
