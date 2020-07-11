# $NetBSD: Makefile,v 1.18 2020/07/11 15:14:29 nia Exp $
#

DISTNAME=		luafilesystem-1.8.0
PKGNAME=		${DISTNAME:S/lua/${LUA_PKGPREFIX}-/}
CATEGORIES=		devel lua
MASTER_SITES=		${MASTER_SITE_GITHUB:=keplerproject/}
GITHUB_PROJECT=		luafilesystem
GITHUB_TAG=		v${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://keplerproject.github.com/luafilesystem/
COMMENT=		File system related library for Lua
LICENSE=		mit

WRKSRC=			${WRKDIR}/luafilesystem-${PKGVERSION_NOREV:S/./_/g}

USE_TOOLS+=		gmake pkg-config
BUILD_TARGET=		lib

TEST_TARGET=		test

MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		CC=${CC}
MAKE_FLAGS+=		CFLAGS="${CFLAGS} -fPIC"
MAKE_FLAGS+=		LUA_VERSION=${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
