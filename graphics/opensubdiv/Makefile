# $NetBSD: Makefile,v 1.1 2026/11/08 15:21:57 ryoon Exp $

DISTNAME=	OpenSubdiv-3_7_0
PKGNAME=	${DISTNAME:tl:S/_/./}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=PixarAnimationStudios/}
GITHUB_PROJECT=	OpenSubdiv
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./_/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.opensubdiv.org/
COMMENT=	Open-Source subdivision surface library
LICENSE=	apache-2.0 # TOMORROW OPEN SOURCE TECHNOLOGY LICENSE 1.0

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17
# For std::clamp and alloca
FORCE_CXX_STD=		gnu++17

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

CMAKE_CONFIGURE_ARGS+=	-DNO_DOC=ON
CMAKE_CONFIGURE_ARGS+=	-DNO_TUTORIALS=ON

.include "../../devel/cmake/build.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../graphics/ptex/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
