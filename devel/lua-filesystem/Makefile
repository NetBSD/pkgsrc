# $NetBSD: Makefile,v 1.2 2012/10/31 11:17:26 asau Exp $
#

DISTNAME=		luafilesystem-1.5.0
PKGNAME=		${DISTNAME:S/lua/lua-/}
CATEGORIES=		devel
MASTER_SITES=		http://github.com/downloads/keplerproject/luafilesystem/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://keplerproject.github.com/luafilesystem/
COMMENT=		File system related library for Lua

USE_TOOLS+=		gmake
BUILD_TARGET=		lib

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
