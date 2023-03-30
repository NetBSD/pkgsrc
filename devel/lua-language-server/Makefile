# $NetBSD: Makefile,v 1.2 2023/03/30 18:41:00 nikita Exp $

DISTNAME=		lua-language-server-3.6.18
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

INSTALLATION_DIRS+=	share/lua-language-server/bin
INSTALLATION_DIRS+=	bin

# TODO: Maybe unbundle (some of) them? (lls does build with them included though)
GITDEPS+=		luamake 915baa5a3141e3f45708b59a7bbc76d7a701d7fe https://github.com/actboy168/luamake luamake
GITDEPS+=		bee.lua a8a503238ee998e5d2995323581bf8926bb49d3a https://github.com/actboy168/bee.lua bee.lua
GITDEPS+=		bee.lua a8a503238ee998e5d2995323581bf8926bb49d3a https://github.com/actboy168/bee.lua luamake/bee.lua
GITDEPS+=		json.lua be1d71ff7afe84942eb3f33b76c8bf75306c4635 https://github.com/actboy168/json.lua json.lua
GITDEPS+=		EmmyLuaCodeStyle fab3d066e14cea1bf1ebe7927d1ceba098e78d12 https://github.com/CppCXY/EmmyLuaCodeStyle EmmyLuaCodeStyle
GITDEPS+=		lovr-docs f08de6bc658f385dfa1b6d1fcba52da5f88b7853 https://github.com/bjornbytes/lovr-docs lovr-api
GITDEPS+=		love-api 495ecc72d994f5d52fc21592dda9d16f4fd75ba1 https://github.com/love2d-community/love-api/ love-api
GITDEPS+=		lpeglabel e25eb35666201b10dc2778d6147ea36a9f6e033d https://github.com/sqmedeiros/lpeglabel lpeglabel

DISTFILES?=			${DEFAULT_DISTFILES}
.for name rev url path in ${GITDEPS}
GITDEPS_DISTFILE:=		${name}-${rev}.tar.gz
GITDEPS_DISTFILES:=		${GITDEPS_DISTFILES} ${GITDEPS_DISTFILE}
SITES.${GITDEPS_DISTFILE}=	-${url}/archive/${rev}.tar.gz
.endfor
DISTFILES:=			${DISTFILES} ${GITDEPS_DISTFILES}

post-extract:
.for dir in EmmyLuaCodeStyle bee.lua json.lua love-api lovr-api lpeglabel luamake
	${RMDIR} ${WRKSRC}/3rd/${dir}
.endfor
.for name rev url path in ${GITDEPS}
	${LN} -s ${WRKDIR}/${name}-${rev} ${WRKSRC}/3rd/${path}
.endfor
	cd ${WRKSRC}/3rd/luamake && \
		${RM} -rf bee.lua && \
		${LN} -s ${WRKDIR}/bee.lua-a8a503238ee998e5d2995323581bf8926bb49d3a bee.lua
	${CP} ${FILESDIR}/lua-language-server ${WRKSRC}/lua-language-server

DATADIR=		${PREFIX}/share/lua-language-server

SUBST_CLASSES+=		wrapper
SUBST_STAGE.wrapper=	pre-build
SUBST_MESSAGE.wrapper=	Patching paths in lua-language-server wrapper script
SUBST_FILES.wrapper=	lua-language-server
SUBST_VARS.wrapper+=	MKTEMP
SUBST_VARS.wrapper+=	DATADIR

do-build:
	ninja -C ${WRKSRC}/3rd/luamake -f compile/ninja/netbsd.ninja
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
