# $NetBSD: Makefile,v 1.7 2018/05/31 09:28:40 adam Exp $

DISTNAME=	uvloop-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uvloop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/uvloop
COMMENT=	Fast implementation of asyncio event loop on top of libuv
LICENSE=	mit AND apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

PYTHON_VERSIONS_ACCEPTED=	36 35

.include "../../devel/libuv/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
