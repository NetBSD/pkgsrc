# $NetBSD: Makefile,v 1.2 2025/10/04 12:39:56 tnn Exp $

DISTNAME=		vulkan-tools-1.4.321.0 # matches vulkan-headers
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=		Vulkan-Tools
GITHUB_TAG=		vulkan-sdk-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Tools/
COMMENT=	Vulkan information and demo utilities
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
