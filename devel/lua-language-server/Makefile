# $NetBSD: Makefile,v 1.13 2024/05/27 09:08:22 nia Exp $

DISTNAME=		lua-language-server-3.8.3
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

GITHUB_SUBMODULES+=	CppCXY EmmyLuaCodeStyle 660a26085ff2c1275392a291063404d54fdd32b9 3rd/EmmyLuaCodeStyle
GITHUB_SUBMODULES+=	actboy168 bee.lua 8c01c7d79612d47f47f17d80304e66ae14d7b953 3rd/bee.lua
GITHUB_SUBMODULES+=	actboy168 json.lua 21c9584d30fa36c542c98b6b1410393318583712 3rd/json.lua
GITHUB_SUBMODULES+=	love2d-community love-api 728ba001f3398fd11b0a3909b919a7caf3e329a4 3rd/love-api
GITHUB_SUBMODULES+=	bjornbytes lovr-docs e89c753e1c2849b7533481fcf058095f8e050b9f 3rd/lovr-api
GITHUB_SUBMODULES+=	sqmedeiros lpeglabel 912b0b9e8641074408ffc2259e069b188e0c717b 3rd/lpeglabel
GITHUB_SUBMODULES+=	actboy168 luamake c086f35cfad0236f74ba380d51f211c52a2c8abc 3rd/luamake
GITHUB_SUBMODULES+=	actboy168 bee.lua 038aef6f41dc09dad43325e5d3cdc3e207b6d3c0 3rd/luamake/bee.lua

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
SUBST_SED.tests=	-e 's,require "test_filewatch",,'

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
