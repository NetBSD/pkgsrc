# $NetBSD: Makefile,v 1.6 2017/09/16 19:53:50 alnsn Exp $

DISTNAME=	lupa-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lupa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/lupa
COMMENT=	Python wrapper around Lua and LuaJIT
LICENSE=	mit

# XXX Find a replacement for luaL_openlib().
LUA_VERSIONS_INCOMPATIBLE=	53

USE_TOOLS+=	pkg-config

.include "options.mk"

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
