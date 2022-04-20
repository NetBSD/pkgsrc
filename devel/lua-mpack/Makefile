# $NetBSD: Makefile,v 1.1 2022/04/20 18:15:51 nia Exp $

DISTNAME=	libmpack-lua-1.0.8
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/libmpack-lua/mpack/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libmpack/}
GITHUB_PROJECT=	libmpack-lua

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libmpack/libmpack-lua
COMMENT=	Lua binding for libmpack
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	DEPS_PREFIX=${PREFIX}
MAKE_FLAGS+=	USE_SYSTEM_LUA=yes
MAKE_FLAGS+=	USE_SYSTEM_MPACK=yes

.include "../../lang/lua/luaversion.mk"

MAKE_FLAGS+=	MPACK_LUA_VERSION=${_LUA_DOT_VERSION}.0

.include "../../devel/libmpack/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
