# $NetBSD: Makefile,v 1.10 2018/12/15 21:12:21 wiz Exp $
#

DISTNAME=		luafilesystem-1.6.3
PKGNAME=		${DISTNAME:S/lua/${LUA_PKGPREFIX}-/}
CATEGORIES=		devel
MASTER_SITES=		-http://github.com/keplerproject/luafilesystem/archive/v_1_6_3.tar.gz

MAINTAINER=		fhajny@NetBSD.org
HOMEPAGE=		http://keplerproject.github.com/luafilesystem/
COMMENT=		File system related library for Lua
LICENSE=		mit

WRKSRC=			${WRKDIR}/luafilesystem-v_${PKGVERSION_NOREV:S/./_/g}

USE_TOOLS+=		gmake
BUILD_TARGET=		lib

MAKE_ENV+=		LUA_CDIR=${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
