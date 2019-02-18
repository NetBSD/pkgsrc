# $NetBSD: Makefile,v 1.12 2019/02/18 13:15:22 wiz Exp $

DISTNAME=	lua-alt-getopt-0.8.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/lua-//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lua-alt-getopt/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/lua-alt-getopt/
COMMENT=	Lua API for getopt similar to getopt_long(3)
LICENSE=	mit

MAKE_FLAGS=	PCNAME.lua=lua-${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

USE_TOOLS+=	pkg-config

.include "../../devel/mk-configure/mk-c.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
