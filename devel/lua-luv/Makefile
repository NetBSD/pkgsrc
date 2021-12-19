# $NetBSD: Makefile,v 1.3 2021/12/19 10:56:37 nia Exp $

DISTNAME=	luv-1.42.0-1
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/-1$/.1/1}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=luvit/}
GITHUB_PROJECT=	luv
GITHUB_TAG=	${DISTNAME:S/^luv-//1}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/luvit/luv
COMMENT=	Bare libuv bindings for Lua
LICENSE=	apache-2.0

USE_CMAKE=	yes

CMAKE_ARGS+=	-DWITH_SHARED_LIBUV=ON
CMAKE_ARGS+=	-DBUILD_MODULE=ON
CMAKE_ARGS+=	-DLUA_BUILD_TYPE=System
CMAKE_ARGS+=	-DWITH_LUA_ENGINE=Lua

.include "../../lang/lua/module.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
