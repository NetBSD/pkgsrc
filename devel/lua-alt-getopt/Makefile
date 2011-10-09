# $NetBSD: Makefile,v 1.4 2011/10/09 10:02:47 cheusov Exp $
#

PKGNAME=	${DISTNAME:S/lua-/${LUA_PKGPREFIX}-/}
DISTNAME=	lua-alt-getopt-0.7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lua-alt-getopt/} \
		http://mova.org/~cheusov/pub/lua_alt_getopt/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/lua-alt-getopt/
COMMENT=	Lua API for getopt similar to getopt_long(3)
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	${LUA_LDIR}

INSTALL_MAKE_FLAGS+=	LUAMODDIR=${PREFIX}/${LUA_LDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
