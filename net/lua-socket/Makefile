# $NetBSD: Makefile,v 1.2 2012/10/23 17:18:36 asau Exp $
#

DISTNAME=		luasocket-2.0.2
PKGNAME=		${LUA_PKGPREFIX}-${DISTNAME:S/lua//}
CATEGORIES=		net
MASTER_SITES=		http://luaforge.net/frs/download.php/2664/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://w3.impa.br/~diego/software/luasocket/
COMMENT=		Network support for the Lua language
LICENSE=		mit

MAKE_FILE=		makefile
USE_TOOLS+=		gmake

LDFLAGS.SunOS=		-lrt -lresolv

INSTALL_MAKE_FLAGS+=	INSTALL_TOP_SHARE=${DESTDIR}${PREFIX}/${LUA_LDIR}
INSTALL_MAKE_FLAGS+=	INSTALL_TOP_LIB=${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
