# $NetBSD: Makefile,v 1.3 2013/06/04 09:21:26 fhajny Exp $
#

DISTNAME=		luafilesystem-1.6.2
PKGNAME=		${DISTNAME:S/lua/lua-/}
CATEGORIES=		devel
MASTER_SITES=		http://github.com/downloads/keplerproject/luafilesystem/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://keplerproject.github.com/luafilesystem/
COMMENT=		File system related library for Lua
LICENSE=		mit

USE_TOOLS+=		gmake
BUILD_TARGET=		lib

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
