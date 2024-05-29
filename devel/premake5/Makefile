# $NetBSD: Makefile,v 1.7 2024/05/29 16:32:18 adam Exp $

PREMAKE5_VERSION=	5.0.0-beta2
DISTNAME=		premake-${PREMAKE5_VERSION}-src
PKGNAME=		premake5-${PREMAKE5_VERSION:S/-beta2/.b2/}
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=premake/}
GITHUB_PROJECT=		premake-core
GITHUB_RELEASE=		v${PREMAKE5_VERSION}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://premake.github.io/
COMMENT=		Build script generator
LICENSE=		modified-bsd

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c99

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

# I see no indication yet where or how this is used, but let's try
# to avoid building the bundled one
DEPENDS+=		lua53-socket-[0-9]*:../../net/lua-socket

.include "../../mk/bsd.prefs.mk"
# maybe fix the build on Darwin.
# if this doesn't work, we need to patch what's in build/gmake2.unix
.if ${OPSYS} == "Darwin"
BUILD_DIRS+=		build/gmake2.macosx
.else
#BUILD_DIRS+=		build/gmake2.unix
BUILD_DIRS+=		build/bootstrap
.endif

INSTALLATION_DIRS=	bin

LDFLAGS+=		-lzip -L${BUILDLINK_PREFIX.libzip}/lib
LDFLAGS+=		-lcurl -L${BUILDLINK_PREFIX.curl}/lib
LDFLAGS+=		-lmbedtls -L${BUILDLINK_PREFIX.mbedtls3}/lib
LDFLAGS+=		-lz -L${BUILDLINK_PREFIX.zlib}/lib

SUBST_CLASSES+=		mk
SUBST_MESSAGE.mk=	Fixing build to link against system libs
SUBST_STAGE.mk=		pre-build
SUBST_FILES.mk=		build/bootstrap/Premake5.make
SUBST_SED.mk+=		-e 's,DEFINES += -DNDEBUG -DLUA_USE_POSIX -DLUA_USE_DLOPEN,DEFINES += -DNDEBUG -DLUA_USE_POSIX -DLUA_USE_DLOPEN -DPREMAKE_COMPRESSION -DPREMAKE_CURL,g'
SUBST_SED.mk+=		-e 's,INCLUDES += -I../../contrib/lua/src -I../../contrib/luashim,INCLUDES += -I../../contrib/lua/src -I../../contrib/luashim -I${BUILDLINK_PREFIX.zlib}/include -I${BUILDLINK_PREFIX.libzip}/include -I${BUILDLINK_PREFIX.curl}/include/curl -I${BUILDLINK_PREFIX.mbedtls3}/include,g'

BUNDLED_LUA_DEFINES?=	-DLUA_USE_DLOPEN -DLUA_USE_POSIX
BUNDLED_LUA_DIR=	${WRKSRC}/contrib/lua/src
BUNDLED_LUA_SRC=	${BUNDLED_LUA_DIR}/lapi.c \
			${BUNDLED_LUA_DIR}/lbaselib.c \
			${BUNDLED_LUA_DIR}/lbitlib.c \
			${BUNDLED_LUA_DIR}/lcode.c \
			${BUNDLED_LUA_DIR}/lcorolib.c \
			${BUNDLED_LUA_DIR}/lctype.c \
			${BUNDLED_LUA_DIR}/ldblib.c \
			${BUNDLED_LUA_DIR}/ldebug.c \
			${BUNDLED_LUA_DIR}/ldo.c \
			${BUNDLED_LUA_DIR}/ldump.c \
			${BUNDLED_LUA_DIR}/lfunc.c \
			${BUNDLED_LUA_DIR}/lgc.c \
			${BUNDLED_LUA_DIR}/linit.c \
			${BUNDLED_LUA_DIR}/liolib.c \
			${BUNDLED_LUA_DIR}/llex.c \
			${BUNDLED_LUA_DIR}/lmathlib.c \
			${BUNDLED_LUA_DIR}/lmem.c \
			${BUNDLED_LUA_DIR}/loadlib.c \
			${BUNDLED_LUA_DIR}/lobject.c \
			${BUNDLED_LUA_DIR}/lopcodes.c \
			${BUNDLED_LUA_DIR}/loslib.c \
			${BUNDLED_LUA_DIR}/lparser.c \
			${BUNDLED_LUA_DIR}/lstate.c \
			${BUNDLED_LUA_DIR}/lstring.c \
			${BUNDLED_LUA_DIR}/lstrlib.c \
			${BUNDLED_LUA_DIR}/ltable.c \
			${BUNDLED_LUA_DIR}/ltablib.c \
			${BUNDLED_LUA_DIR}/ltm.c \
			${BUNDLED_LUA_DIR}/lundump.c \
			${BUNDLED_LUA_DIR}/lutf8lib.c \
			${BUNDLED_LUA_DIR}/lvm.c \
			${BUNDLED_LUA_DIR}/lzio.c

# the upstream directive how to build this results in too much work
# and errors.
do-configure:
	# bootstrap premake5
	# uses includes for some lua sources, has to use bundled lua.
	${MKDIR} -p ${WRKSRC}/build/bootstrap
	cd ${WRKSRC} && \
		${MAKE_ENV} ${CC} -o build/bootstrap/premake_bootstrap \
		-DPREMAKE_NO_BUILTIN_SCRIPTS \
		${BUNDLED_LUA_DEFINES} \
		-Icontrib/lua/src \
		-Icontrib/luashim \
		-I${BUILDLINK_PREFIX.libuuid}/include/uuid \
		-L${PREFIX}/lib \
		src/host/*.c ${BUNDLED_LUA_SRC} \
		-lm -ldl -lrt -luuid ${LDFLAGS} ${CFLAGS}
	cd ${WRKSRC} && \
		./build/bootstrap/premake_bootstrap embed
	cd ${WRKSRC} && \
		./build/bootstrap/premake_bootstrap \
		--to=build/bootstrap \
		--no-zlib \
		--no-curl \
		--no-luasocket \
		gmake2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake5 \
		${DESTDIR}${PREFIX}/bin/

# libm, libgcc, librt
.include "../../lang/lua53/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/mbedtls3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
