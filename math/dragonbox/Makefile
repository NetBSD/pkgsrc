# $NetBSD: Makefile,v 1.1 2022/08/24 12:53:24 ryoon Exp $

DISTNAME=	dragonbox-${GITHUB_TAG}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=jk-jeon/}
GITHUB_PROJECT=	dragonbox
GITHUB_TAG=	1.1.3

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jk-jeon/dragonbox/
COMMENT=	Floating-point to binary-to-decimal conversion library
LICENSE=	boost-license OR apache-2.0 # with LLVM exceptions

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.pkg.mk"
