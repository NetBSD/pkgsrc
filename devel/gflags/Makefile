# $NetBSD: Makefile,v 1.1 2016/12/06 00:34:18 rodent Exp $

DISTNAME=	gflags-${PORTVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gflags/}
GITHUB_PROJECT=	gflags
GITHUB_TAG=	v${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
HOMEPAGE=	https://github.com/gflags/gflags
COMMENT=	Commandline flags module for C++
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run
REPLACE_BASH=	src/gflags_completions.sh
USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DBUILD_STATIC_LIBS:BOOL=ON -DBUILD_TESTING:BOOL=ON
CMAKE_ARGS+=	-DGFLAGS_NAMESPACE:STRING=gflags
PTHREAD_OPTS+=	require

TEST_TARGET=	test

PORTVERSION=	2.1.2

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
