# $NetBSD: Makefile,v 1.16 2026/02/26 17:09:47 sborrill Exp $

DISTNAME=		luasocket-3.1.0
PKGREVISION=		1
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME:S/lua//}
CATEGORIES=		net lua
MASTER_SITES=		-https://github.com/lunarmodules/luasocket/archive/v${PKGVERSION}.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://lunarmodules.github.io/luasocket/
COMMENT=		Network support for the Lua language
LICENSE=		mit

MAKE_FILE=		makefile

CFLAGS.Darwin=		-DUNIX_HAS_SUN_LEN
CFLAGS.FreeBSD=		-DUNIX_HAS_SUN_LEN
CFLAGS.NetBSD=		-DUNIX_HAS_SUN_LEN
LDFLAGS.SunOS=		-lrt -lresolv -lsocket -lnsl

MAKE_FLAGS+=		LUAV=${_LUA_DOT_VERSION}
MAKE_FLAGS+=		LUAINC_linux_base=${PREFIX}/include
MAKE_FLAGS+=		LUAPREFIX_linux=${PREFIX}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
