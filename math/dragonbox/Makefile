# $NetBSD: Makefile,v 1.4 2023/07/30 08:24:21 nia Exp $

DISTNAME=	dragonbox-${GITHUB_TAG}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=jk-jeon/}
GITHUB_PROJECT=	dragonbox
GITHUB_TAG=	1.1.3

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jk-jeon/dragonbox/
COMMENT=	Floating-point to binary-to-decimal conversion library
LICENSE=	boost-license OR apache-2.0 # with LLVM exceptions

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

USE_CXX_FEATURES+=	c++17

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
