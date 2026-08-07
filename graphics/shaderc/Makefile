# $NetBSD: Makefile,v 1.3 2026/08/07 10:40:06 kikadf Exp $

# to get current vulkan SDK version, but we need to override GITHUB_TAG locally
.include "../../graphics/vulkan-headers/Makefile.common"

DISTNAME=	shaderc-2026.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/shaderc/
COMMENT=	Tools, libraries, and tests for Vulkan shader compilation
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config

CXXFLAGS+=	-I${BUILDLINK_PREFIX.glslang}/include/glslang

GITHUB_SUBMODULES+=	KhronosGroup SPIRV-Tools vulkan-sdk-${SDK_VERSION} third_party/SPIRV-Tools

# needs local googletest checkout
CMAKE_CONFIGURE_ARGS+=	-DSHADERC_SKIP_TESTS=ON
CMAKE_CONFIGURE_ARGS+=	-Dglslang_SOURCE_DIR:PATH=${PREFIX}/include/glslang
CMAKE_CONFIGURE_ARGS+=	-Dspirv-tools_SOURCE_DIR:PATH=${WRKSRC}/third_party/SPIRV-Tools

PKGCONFIG_OVERRIDE+=	cmake/shaderc.pc.in
PKGCONFIG_OVERRIDE+=	cmake/shaderc_combined.pc.in
PKGCONFIG_OVERRIDE+=	cmake/shaderc_static.pc.in

.include "../../lang/python/tool.mk"
.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.glslang+=		glslang>=${SDK_VERSION}
.include "../../graphics/glslang/buildlink3.mk"
BUILDLINK_API_DEPENDS.spirv-headers+=	spirv-headers>=${SDK_VERSION}
.include "../../parallel/spirv-headers/buildlink3.mk"
BUILDLINK_API_DEPENDS.spirv-tools+=	spirv-tools>=${SDK_VERSION}
.include "../../parallel/spirv-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
