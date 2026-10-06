# $NetBSD: Makefile,v 1.16 2026/10/06 18:44:22 wiz Exp $

DISTNAME=		lua-language-server-3.19.1
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 099975
PKG_FAIL_REASON+=	"Requires EVFILT_USER, unavailable on NetBSD 9.x and prior"
.endif

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS+=	share/lua-language-server/bin
INSTALLATION_DIRS+=	bin

GITHUB_SUBMODULES+=	CppCXY EmmyLuaCodeStyle 8c4289b7617ccdb0b247a6171f111f28ac7ae969 3rd/EmmyLuaCodeStyle
GITHUB_SUBMODULES+=	actboy168 bee.lua f55b6988e8d9564816a555118b0e76564ef9a283 3rd/bee.lua
GITHUB_SUBMODULES+=	actboy168 json.lua 08095fd2cdfde8f49a5f5b54b35ec7b3d4906a36 3rd/json.lua
GITHUB_SUBMODULES+=	love2d-community love-api 853639288547618dece86c3a8e52348fe304eba2 3rd/love-api
GITHUB_SUBMODULES+=	bjornbytes lovr-docs e89c753e1c2849b7533481fcf058095f8e050b9f 3rd/lovr-api
GITHUB_SUBMODULES+=	sqmedeiros lpeglabel 912b0b9e8641074408ffc2259e069b188e0c717b 3rd/lpeglabel
GITHUB_SUBMODULES+=	actboy168 luamake 4c4bd16c9b0c1d773402fc15c76367f7899a1f91 3rd/luamake
GITHUB_SUBMODULES+=	actboy168 bee.lua 466c4f071a17ab7c31e402383b0a2097b03535ba 3rd/luamake/bee.lua
GITHUB_SUBMODULES+=	LuaCATS openresty 3bec36f0f645bb38b3c8208990d5c36feb66ce3d meta/3rd/OpenResty
GITHUB_SUBMODULES+=	LuaCATS cocos4.0 c0b2259e0d367561fd4563ae114b029b4dfe3a8f meta/3rd/Cocos4.0
GITHUB_SUBMODULES+=	LuaCATS defold 05379b40fb3084d82f7270475e42da8d521c4dae meta/3rd/Defold
GITHUB_SUBMODULES+=	LuaCATS jass 80d85cbbfd8ae2473fb39c7df4be814602f5bc4f meta/3rd/Jass
GITHUB_SUBMODULES+=	LuaCATS	bee c8ce19fd5536a7e98ef186d1d75825f0bb8c9216 meta/3rd/bee
GITHUB_SUBMODULES+=	LuaCATS busted 5ed85d0e016a5eb5eca097aa52905eedf1b180f1 meta/3rd/busted
GITHUB_SUBMODULES+=	LuaCATS ffi-reflect e9037efca4021a15552b281f5e91418afd370d8f meta/3rd/ffi-reflect
GITHUB_SUBMODULES+=	LuaCATS luafilesystem 9b5cfc15be744c829c66519cb11e49669ae7e39b meta/3rd/lfs
GITHUB_SUBMODULES+=	LuaCATS	love2d 98f7684525a6e866ffa6df449b7aef406a807dae meta/3rd/love2d
GITHUB_SUBMODULES+=	LuaCATS lovr 3ba215f98e1647111b50b311d45c31338fdc615f meta/3rd/lovr
GITHUB_SUBMODULES+=	LuaCATS luaecs 21192fbdccc0f140dae2f74f7c3ec7d74e2aadd0 meta/3rd/luaecs
GITHUB_SUBMODULES+=	LuaCATS luassert d3528bb679302cbfdedefabb37064515ab95f7b9 meta/3rd/luassert
GITHUB_SUBMODULES+=	LuaCATS luv 3615eb12c94a7cfa7184b8488cf908abb5e94c9c  meta/3rd/luv
GITHUB_SUBMODULES+=	LuaCATS skynet afa6717ac4f71e42012fa2ebf4b410d04db647ae meta/3rd/skynet

post-extract:
	${CP} ${FILESDIR}/lua-language-server ${WRKSRC}/lua-language-server

DATADIR=		${PREFIX}/share/lua-language-server

SUBST_CLASSES+=		wrapper
SUBST_STAGE.wrapper=	pre-build
SUBST_MESSAGE.wrapper=	Patching paths in lua-language-server wrapper script
SUBST_FILES.wrapper=	lua-language-server
SUBST_VARS.wrapper+=	MKTEMP
SUBST_VARS.wrapper+=	DATADIR

do-build:
	# probably needs much more fixes for systems noch supported by luamake.
	${PREFIX}/bin/ninja -C ${WRKSRC}/3rd/luamake -f compile/ninja/${OPSYS:tl}.ninja notest
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./3rd/luamake/luamake \
	    -flags " ${CFLAGS}" -ldflags " ${LDFLAGS}" -v all

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
