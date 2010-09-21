# $NetBSD: Makefile,v 1.1.1.1 2010/09/21 09:30:41 fhajny Exp $
#

DISTNAME=		luafilesystem-1.5.0
PKGNAME=		${DISTNAME:S/lua/lua-/}
CATEGORIES=		devel
MASTER_SITES=		http://github.com/downloads/keplerproject/luafilesystem/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://keplerproject.github.com/luafilesystem/
COMMENT=		File system related library for Lua

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
BUILD_TARGET=		lib

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
