# $NetBSD: Makefile,v 1.8 2026/01/06 22:11:49 wiz Exp $

DISTNAME=	lua-rapidjson-0.7.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua-//1}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=xpol/}
GITHUB_PROJECT=	lua-rapidjson
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xpol/lua-rapidjson
COMMENT=	JSON module for Lua, based on the very fast RapidJSON C++ library
LICENSE=	mit

TEST_DEPENDS+=	${LUA_PKGPREFIX}-utf8-[0-9]*:../../textproc/lua-utf8

USE_LANGUAGES=	c c++

LUA_USE_BUSTED=	yes

LUA_VERSIONS_INCOMPATIBLE+=	55

CMAKE_CONFIGURE_ARGS+=	-DLUA_RAPIDJSON_VERSION=${PKGVERSION}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

USE_CXX_FEATURES+=	c++11

INSTALLATION_DIRS+=	${LUA_CDIR}

pre-configure:
	# Use the standard cmake mechanism for finding Lua.
	${RM} -f ${WRKSRC}/cmake/Modules/FindLua.cmake

do-install:
	${INSTALL_LIB} ${WRKSRC}/${CMAKE_BUILD_DIR}/rapidjson.so ${DESTDIR}${PREFIX}/${LUA_CDIR}

.include "../../devel/cmake/build.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
