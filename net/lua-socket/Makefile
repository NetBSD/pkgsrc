# $NetBSD: Makefile,v 1.8 2014/05/03 13:14:37 alnsn Exp $

DISTNAME=		luasocket-3.0-rc1
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME:S/lua//:S/-rc/rc/}
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		-https://github.com/diegonehab/luasocket/archive/v3.0-rc1.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://w3.impa.br/~diego/software/luasocket/
COMMENT=		Network support for the Lua language
LICENSE=		mit

MAKE_FILE=		makefile

LDFLAGS.SunOS=		-lrt -lresolv

MAKE_FLAGS+=		LUAV=${_LUA_DOT_VERSION}
MAKE_FLAGS+=		LUAINC_linux_base=${PREFIX}/include
MAKE_FLAGS+=		LUAPREFIX_linux=${PREFIX}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
