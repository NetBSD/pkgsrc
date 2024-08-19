# $NetBSD: Makefile,v 1.33 2024/08/19 13:34:54 adam Exp $

DISTNAME=	uvloop-0.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uvloop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/uvloop
COMMENT=	Fast implementation of asyncio event loop on top of libuv
LICENSE=	mit AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.36:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=60:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	libuv>=1.48.0:../../devel/libuv
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/libuv/buildlink3.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL:test
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
