# $NetBSD: Makefile,v 1.5 2024/08/25 06:19:16 wiz Exp $

DISTNAME=	lua-rapidjson-0.7.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua-//1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=xpol/}
GITHUB_PROJECT=	lua-rapidjson
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/xpol/lua-rapidjson
COMMENT=	JSON module for Lua, based on the very fast RapidJSON C++ library
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

LUA_USE_BUSTED=	yes

TEST_DEPENDS+=	${LUA_PKGPREFIX}-utf8-[0-9]*:../../textproc/lua-utf8

CMAKE_CONFIGURE_ARGS+=	-DLUA_RAPIDJSON_VERSION=${PKGVERSION}

USE_CXX_FEATURES+=	c++11

INSTALLATION_DIRS+=	${LUA_CDIR}

pre-configure:
	# Use the standard cmake mechanism for finding Lua.
	${RM} -f ${WRKSRC}/cmake/Modules/FindLua.cmake

do-install:
	${INSTALL_LIB} ${WRKSRC}/rapidjson.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
