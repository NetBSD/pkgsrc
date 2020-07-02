# $NetBSD: Makefile,v 1.1 2020/07/02 20:48:09 nia Exp $

DISTNAME=	luv-1.36.0-0
PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME:S/-0//1}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=luvit/}
GITHUB_PROJECT=	luv
GITHUB_RELEASE=	${PKGVERSION_NOREV}-0

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
