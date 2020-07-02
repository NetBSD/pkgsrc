# $NetBSD: Makefile,v 1.1 2020/07/02 10:59:24 nia Exp $

DISTNAME=	lua-term-0.07
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hoelzro/}
GITHUB_PROJECT=	lua-term

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hoelzro/lua-term
COMMENT=	Lua module for manipulating a terminal
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	LUA_DIR=${PREFIX}
MAKE_FLAGS+=	LUA_VER=${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
MAKE_FLAGS+=	LUA_INC=${PREFIX}/${LUA_INCDIR}
MAKE_FLAGS+=	LUA_LIBDIR=${PREFIX}/${LUA_CDIR}/term
MAKE_FLAGS+=	LUA_SHARE=${PREFIX}/${LUA_LDIR}/term

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
