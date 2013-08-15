# $NetBSD: Makefile,v 1.18 2013/08/15 06:32:06 obache Exp $
#

DISTNAME=	luaexpat-1.2.0
PKGNAME=	${DISTNAME:S/lua/lua-/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://matthewwild.co.uk/projects/luaexpat/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matthewwild.co.uk/projects/projects
COMMENT=	XML parser for LUA based on expat
LICENSE=	mit

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
