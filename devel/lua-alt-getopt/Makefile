# $NetBSD: Makefile,v 1.10 2017/01/19 18:52:07 agc Exp $

DISTNAME=	lua-alt-getopt-0.7.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lua-alt-getopt/}
MASTER_SITES+=	http://mova.org/~cheusov/pub/lua_alt_getopt/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/lua-alt-getopt/
COMMENT=	Lua API for getopt similar to getopt_long(3)
LICENSE=	mit

USE_BSD_MAKEFILE=	yes

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	${LUA_LDIR}

INSTALL_MAKE_FLAGS+=	LUAMODDIR=${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
