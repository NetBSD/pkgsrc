# $NetBSD: Makefile,v 1.14 2026/03/31 10:46:00 adam Exp $

DISTNAME=	glm-1.0.3
PKGREVISION=	1
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_GITHUB:=g-truc/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://glm.g-truc.net/
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL
LICENSE=	mit

USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
