# $NetBSD: Makefile,v 1.2 2017/03/17 14:49:58 adam Exp $

DISTNAME=	gflags-2.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gflags/}

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	https://github.com/gflags/gflags
COMMENT=	Commandline flags module for C++
LICENSE=	modified-bsd

GITHUB_PROJECT=	gflags
GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run
REPLACE_BASH=	src/gflags_completions.sh
USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DBUILD_STATIC_LIBS:BOOL=ON
CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=ON
CMAKE_ARGS+=	-DGFLAGS_NAMESPACE:STRING=gflags
PTHREAD_OPTS+=	require

PKGCONFIG_OVERRIDE=	cmake/package.pc.in

TEST_TARGET=	test

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
