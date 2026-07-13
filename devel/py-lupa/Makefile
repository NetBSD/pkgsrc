# $NetBSD: Makefile,v 1.22 2026/07/13 12:18:24 adam Exp $

DISTNAME=	lupa-2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lupa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scoder/lupa
COMMENT=	Python wrapper around Lua and LuaJIT
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.11:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
