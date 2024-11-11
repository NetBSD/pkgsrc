# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:15 wiz Exp $

DISTNAME=	lupa-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lupa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scoder/lupa
COMMENT=	Python wrapper around Lua and LuaJIT
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.9:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
