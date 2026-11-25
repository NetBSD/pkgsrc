# $NetBSD: Makefile,v 1.8 2026/11/25 21:03:12 wiz Exp $

.include "../../graphics/vulkan-headers/Makefile.common"

DISTNAME=		vulkan-tools-${SDK_VERSION}
PKGREVISION=		1
CATEGORIES=		graphics
GITHUB_PROJECT=		Vulkan-Tools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/Vulkan-Tools/
COMMENT=	Vulkan information and demo utilities
LICENSE=	apache-2.0

DEPENDS+=	vulkan-loader>=${SDK_VERSION}:../../graphics/vulkan-loader

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
BUILDLINK_API_DEPENDS.vulkan-headers+=	vulkan-headers>=${SDK_VERSION}
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
