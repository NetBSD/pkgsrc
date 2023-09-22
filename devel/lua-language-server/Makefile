# $NetBSD: Makefile,v 1.11 2023/09/22 20:17:21 vins Exp $

DISTNAME=		lua-language-server-3.6.21
PKGNAME=		${DISTNAME:S/lua/${LUA_PKGPREFIX}/}
CATEGORIES=		devel lua
MASTER_SITES=		${MASTER_SITE_GITHUB:=luals/}
GITHUB_PROJECT=		lua-language-server
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://github.com/luals/lua-language-server/
COMMENT=		Language server for Lua
LICENSE=		mit

MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		CC=${CC:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q} -fPIC
MAKE_FLAGS+=		LUA_VERSION=${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}

USE_TOOLS+=		pax mktemp
TOOL_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build
# 3rd/luamake, maybe needs path patching:
DEPENDS+=		clang-[0-9]*:../../lang/clang

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD=		c++17

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS+=	share/lua-language-server/bin
INSTALLATION_DIRS+=	bin

# TODO: Maybe unbundle (some of) them? (lls does build with them included though)
GITHUB_SUBMODULES+=	CppCXY EmmyLuaCodeStyle 82aca211b6ee403a832412b9f7938db797c564d8 3rd/EmmyLuaCodeStyle
GITHUB_SUBMODULES+=	actboy168 bee.lua a131e39521e230ea2bbca20cb6b1c5abbc6a437b 3rd/bee.lua
GITHUB_SUBMODULES+=	actboy168 json.lua bd7b7787bb8b586e59b5afe5886dd1b76c86eb56 3rd/json.lua
GITHUB_SUBMODULES+=	love2d-community love-api ab6dc6756683686b5506107116f994253aef5a20 3rd/love-api
GITHUB_SUBMODULES+=	bjornbytes lovr-docs 441a21a6eb32e611be889cadf41df16938eda43d 3rd/lovr-api
GITHUB_SUBMODULES+=	sqmedeiros lpeglabel e25eb35666201b10dc2778d6147ea36a9f6e033d 3rd/lpeglabel
GITHUB_SUBMODULES+=	actboy168 luamake 22f861ac8444d1b85ceb29561b2a599fcbff4e3f 3rd/luamake
GITHUB_SUBMODULES+=	actboy168 bee.lua 8ff095021f73f5883d4b67ba6eb233eae44f3bb9 3rd/luamake/bee.lua

post-extract:
	${CP} ${FILESDIR}/lua-language-server ${WRKSRC}/lua-language-server

DATADIR=		${PREFIX}/share/lua-language-server

SUBST_CLASSES+=		wrapper
SUBST_STAGE.wrapper=	pre-build
SUBST_MESSAGE.wrapper=	Patching paths in lua-language-server wrapper script
SUBST_FILES.wrapper=	lua-language-server
SUBST_VARS.wrapper+=	MKTEMP
SUBST_VARS.wrapper+=	DATADIR

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing path to installed headers.
SUBST_FILES.path=	3rd/luamake/compile/ninja/netbsd.ninja
SUBST_FILES.path+=	3rd/bee.lua/compile/common.lua
SUBST_SED.path=		-e 's,/usr/pkg,${PREFIX},'

SUBST_CLASSES+=		tests
SUBST_STAGE.tests=	pre-configure
SUBST_MESSAGE.tests=	Do not run randomly failing filewatch tests.
SUBST_FILES.tests+=	3rd/bee.lua/test/test.lua
SUBST_FILES.tests+=	3rd/luamake/bee.lua/test/test.lua
SUBST_SED.tests=	-e "s,require 'test_filewatch',,"

do-build:
	# probably needs much more fixes for systems noch supported by luamake.
	${PREFIX}/bin/ninja -C ${WRKSRC}/3rd/luamake -f compile/ninja/${OPSYS:tl}.ninja
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./3rd/luamake/luamake -v

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lua-language-server ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lua-language-server ${DESTDIR}${DATADIR}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/main.lua ${DESTDIR}${DATADIR}/bin
	${INSTALL_DATA} ${WRKSRC}/debugger.lua ${DESTDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/main.lua ${DESTDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw locale ${DESTDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw meta ${DESTDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw script ${DESTDIR}${DATADIR}

.include "../../devel/libinotify/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
