# $NetBSD: Makefile,v 1.30 2022/10/19 14:25:18 nia Exp $

DISTNAME=	uvloop-0.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uvloop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/uvloop
COMMENT=	Fast implementation of asyncio event loop on top of libuv
LICENSE=	mit AND apache-2.0

DEPENDS+=	libuv>=1.43.0:../../devel/libuv
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/libuv/buildlink3.mk"
.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL:test
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
