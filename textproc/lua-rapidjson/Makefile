# $NetBSD: Makefile,v 1.1 2020/07/08 17:00:03 nia Exp $

DISTNAME=	lua-rapidjson-0.6.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua-//1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=xpol/}
GITHUB_PROJECT=	lua-rapidjson
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/xpol/lua-rapidjson
COMMENT=	JSON module for Lua, based on the very fast RapidJSON C++ library
LICENSE=	mit

TEST_DEPENDS+=	${LUA_PKGPREFIX}-busted-[0-9]*:../../devel/lua-busted

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# C++11
GCC_REQD+=	4.7

INSTALLATION_DIRS+=	${LUA_CDIR}

pre-configure:
	# Use the standard cmake mechanism for finding Lua.
	${RM} -f ${WRKSRC}/cmake/Modules/FindLua.cmake

do-install:
	${INSTALL_LIB} ${WRKSRC}/rapidjson.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/busted${_LUA_DOT_VERSION}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
