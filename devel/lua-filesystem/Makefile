# $NetBSD: Makefile,v 1.5 2013/09/13 12:09:37 fhajny Exp $
#

DISTNAME=		luafilesystem-1.6.2
PKGNAME=		${DISTNAME:S/lua/lua-/}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://github.com/downloads/keplerproject/luafilesystem/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://keplerproject.github.com/luafilesystem/
COMMENT=		File system related library for Lua
LICENSE=		mit

USE_TOOLS+=		gmake
BUILD_TARGET=		lib

MAKE_ENV+=		LUA_CDIR=${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
