# $NetBSD: Makefile,v 1.39 2025/10/20 08:12:21 adam Exp $

DISTNAME=	uvloop-0.22.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uvloop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/uvloop
COMMENT=	Fast implementation of asyncio event loop on top of libuv
LICENSE=	mit AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.1:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	libuv>=1.48.0:../../devel/libuv
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.10.5:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

.include "../../devel/libuv/buildlink3.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL:test
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
