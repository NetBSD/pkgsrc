# $NetBSD: Makefile,v 1.1 2020/07/08 12:15:08 nia Exp $

DISTNAME=	luasystem-0.2.1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=o-lim/}
GITHUB_PROJECT=	luasystem
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/o-lim/luasystem
COMMENT=	Platform independent system call library for Lua
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config
BUILD_DIRS=	src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
MAKE_FLAGS+=	PLAT=macosx
.else
MAKE_FLAGS+=	PLAT=freebsd
.endif

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	LUA_VERSION=${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}
MAKE_FLAGS+=	CC=${CC}
MAKE_FLAGS+=	LD=${CC}
MAKE_FLAGS+=	CDIR=${LUA_CDIR}
MAKE_FLAGS+=	LDIR=${LUA_LDIR}
MAKE_FLAGS+=	LUAINC=${PREFIX}/${LUA_INCDIR}

MAKE_FLAGS+=	INSTALL_DIR=${INSTALL_DATA_DIR:Q}
MAKE_FLAGS+=	INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=	INSTALL_EXEC=${INSTALL_LIB:Q}

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR} ${LUA_LDIR}/system

post-install:
	${INSTALL_DATA} ${WRKSRC}/system/*.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/system

.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
