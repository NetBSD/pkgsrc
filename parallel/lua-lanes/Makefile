# $NetBSD: Makefile,v 1.1 2020/07/11 16:15:08 nia Exp $

DISTNAME=	lanes-3.13.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=LuaLanes/}
GITHUB_PROJECT=	lanes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lualanes.github.io/lanes/
COMMENT=	Lightweight, native, lazy evaluating multithreading library for Lua
LICENSE=	mit

USE_TOOLS+=	gmake

BUILD_DIRS+=	src

MAKE_FLAGS+=	LIBFLAG="${LDFLAGS} -shared"

INSTALLATION_DIRS+=	${LUA_DOCDIR}
INSTALLATION_DIRS+=	${LUA_LDIR}
INSTALLATION_DIRS+=	${LUA_CDIR}/lanes

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/lanes/core.so \
		${DESTDIR}${PREFIX}/${LUA_CDIR}/lanes/core.so
	${INSTALL_DATA} ${WRKSRC}/src/lanes.lua \
		${DESTDIR}${PREFIX}/${LUA_LDIR}/lanes.lua
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${WRKSRC}/docs/*.png \
		${DESTDIR}${PREFIX}/${LUA_DOCDIR}

do-test:
	cd ${WRKSRC}/tests && \
		LUA_PATH="${WRKSRC}/src/?.lua;${WRKSRC}/tests/?.lua" \
		LUA_CPATH="${WRKSRC}/src/?.so" \
		${LUA_INTERPRETER} basic.lua

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
