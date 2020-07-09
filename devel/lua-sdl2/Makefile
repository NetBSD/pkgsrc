# $NetBSD: Makefile,v 1.2 2020/07/09 15:03:35 nia Exp $

DISTNAME=	luasdl2-2.0.5.6.0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/^lua//1}
PKGREVISION=	1
CATEGORIES=	devel lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tangent128/}
GITHUB_PROJECT=	luasdl2
GITHUB_TAG=	v2.0.5-6.0

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/Tangent128/luasdl2
COMMENT=	Pure C binding of SDL 2.0 for Lua
LICENSE=	isc

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DWITH_DOCSDIR=${LUA_DOCDIR}
CMAKE_ARGS+=	-DWITH_LUAVER="user"
CMAKE_ARGS+=	-DLUA_LIBDIR=${LUA_CDIR}

.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../mk/bsd.pkg.mk"
