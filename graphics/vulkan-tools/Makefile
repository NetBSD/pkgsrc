# $NetBSD: Makefile,v 1.3 2026/04/13 13:17:59 kikadf Exp $

.include "../../graphics/vulkan-headers/Makefile.common"

DISTNAME=		vulkan-tools-${SDK_VERSION}
CATEGORIES=		graphics
GITHUB_PROJECT=		Vulkan-Tools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Tools/
COMMENT=	Vulkan information and demo utilities
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
