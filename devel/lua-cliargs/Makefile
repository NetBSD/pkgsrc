# $NetBSD: Makefile,v 1.1 2020/07/08 15:36:21 nia Exp $

DISTNAME=	lua_cliargs-3.0.2
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua_//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=amireh/}
GITHUB_PROJECT=	lua_cliargs
GITHUB_TAG=	v3.0-2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/amireh/lua_cliargs
COMMENT=	Command-line argument parsing module for Lua
LICENSE=	mit

NO_BUILD=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}/cliargs
INSTALLATION_DIRS+=	${LUA_LDIR}/cliargs/utils

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/cliargs.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}
	${INSTALL_DATA} ${WRKSRC}/src/cliargs/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cliargs
	${INSTALL_DATA} ${WRKSRC}/src/cliargs/utils/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/cliargs/utils

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
