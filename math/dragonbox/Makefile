# $NetBSD: Makefile,v 1.3 2023/07/20 19:36:00 ryoon Exp $

DISTNAME=	dragonbox-${GITHUB_TAG}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=jk-jeon/}
GITHUB_PROJECT=	dragonbox
GITHUB_TAG=	1.1.3

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jk-jeon/dragonbox/
COMMENT=	Floating-point to binary-to-decimal conversion library
LICENSE=	boost-license OR apache-2.0 # with LLVM exceptions

USE_LANGUAGES=	c gnu++17

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
