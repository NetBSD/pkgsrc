# $NetBSD: Makefile,v 1.26 2023/04/19 08:22:24 wiz Exp $

DISTNAME=	luaexpat-1.5.1
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}-/}
CATEGORIES=	textproc lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=lunarmodules/}
GITHUB_PROJECT=	luaexpat

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://matthewwild.co.uk/projects/luaexpat/
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

BUILDLINK_API_DEPENDS.expat+=	expat>=2.4
.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
