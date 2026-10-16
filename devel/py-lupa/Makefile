# $NetBSD: Makefile,v 1.24 2026/10/16 19:43:50 adam Exp $

DISTNAME=	lupa-2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lupa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scoder/lupa
COMMENT=	Python wrapper around Lua and LuaJIT
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.11:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	gmake pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
