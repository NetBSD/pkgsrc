# $NetBSD: Makefile,v 1.4 2023/01/24 18:36:22 wiz Exp $

DISTNAME=	gflags-2.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gflags/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	https://github.com/gflags/gflags
COMMENT=	Commandline flags module for C++
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run
TEST_TARGET=	test

REPLACE_BASH=	src/gflags_completions.sh
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DBUILD_STATIC_LIBS:BOOL=ON
CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=ON
CMAKE_ARGS+=	-DGFLAGS_NAMESPACE:STRING=gflags
PTHREAD_OPTS+=	require

PKGCONFIG_OVERRIDE=	cmake/package.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
