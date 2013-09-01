# $NetBSD: Makefile,v 1.19 2013/09/01 04:48:21 ryoon Exp $
#

DISTNAME=	lua-expat-1f41c74ce686
PKGNAME=	${LUA_PKGPREFIX}-expat-1.2.0.20130831
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matthewwild.co.uk/projects/luaexpat/
COMMENT=	XML parser for LUA based on expat
LICENSE=	mit

USE_TOOLS+=	gmake

CFLAGS+=	-fPIC

MAKE_FLAGS+=	LUA_DIR=${BUILDLINK_PREFIX.lua}
MAKE_FLAGS+=	LUA_CDIR=${PREFIX}/${LUA_CDIR}
MAKE_FLAGS+=	LUA_LDIR=${PREFIX}/${LUA_LDIR}
MAKE_FLAGS+=	LUA_INC=-I${BUILDLINK_PREFIX.lua}/include
MAKE_FLAGS+=	EXPAT_INC=-I${BUILDLINK_PREFIX.expat}/include
MAKE_FLAGS+=	LUA_VERSION_NUM=${LUA_VERSION_MAJOR}0${LUA_VERSION_MINOR}
BUILD_TARGET=	lib

INSTALLATION_DIRS=	${LUA_CDIR} ${LUA_LDIR}/lxp

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
