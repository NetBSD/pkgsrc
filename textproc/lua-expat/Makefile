# $NetBSD: Makefile,v 1.14 2009/12/15 12:43:04 fhajny Exp $
#

DISTNAME=	luaexpat-1.1
PKGNAME=	${DISTNAME:S/lua/lua-/}.0
CATEGORIES=	textproc
MASTER_SITES=	http://luaforge.net/frs/download.php/2469/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.keplerproject.org/luaexpat/
COMMENT=	XML parser for LUA based on expat
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
MAKE_FILE=	makefile

CFLAGS+=	-fPIC

MAKE_FLAGS+=	LUA_DIR=${BUILDLINK_PREFIX.lua}
MAKE_FLAGS+=	LUA_INC=${BUILDLINK_PREFIX.lua}/include
MAKE_FLAGS+=	EXPAT_INC=${BUILDLINK_PREFIX.expat}/include
MAKE_FLAGS+=	LUA_VERSION_NUM=${LUA_VERSION_MAJOR}0${LUA_VERSION_MINOR}
BUILD_TARGET=	lib

INSTALLATION_DIRS=	${LUA_CDIR} ${LUA_LDIR} share/examples/lua

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/lxp.so.${PKGVERSION} ${DESTDIR}${PREFIX}/${LUA_CDIR}/lxp.so
	${INSTALL_DATA} ${WRKSRC}/src/lxp/lom.lua ${DESTDIR}${PREFIX}/${LUA_LDIR}/lom.lua
	${INSTALL_DATA} ${WRKSRC}/tests/test.lua ${DESTDIR}${PREFIX}/share/examples/lua/lxp.lua

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
