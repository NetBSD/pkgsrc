# $NetBSD: Makefile,v 1.4 2026/08/27 11:17:18 adam Exp $

# to get current vulkan SDK version, but we need to override GITHUB_TAG locally
.include "../../graphics/vulkan-headers/Makefile.common"

DISTNAME=	shaderc-2026.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/shaderc
COMMENT=	Tools, libraries, and tests for Vulkan shader compilation
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config

CXXFLAGS+=	-I${BUILDLINK_PREFIX.glslang}/include/glslang

# needs local googletest checkout
CMAKE_CONFIGURE_ARGS+=	-DSHADERC_SKIP_TESTS=ON
CMAKE_CONFIGURE_ARGS+=	-DSHADERC_SKIP_COPYRIGHT_CHECK=ON

PKGCONFIG_OVERRIDE+=	cmake/shaderc.pc.in
PKGCONFIG_OVERRIDE+=	cmake/shaderc_combined.pc.in
PKGCONFIG_OVERRIDE+=	cmake/shaderc_static.pc.in

# Remove third_pary dir to avoid symbol conflicts with installed spirv-tools.
pre-configure:
	${RM} -f -r ${WRKSRC}/third_party

pre-build:
	${ECHO} "\"${PKGNAME}\"" > ${WRKSRC}/${CMAKE_BUILD_DIR}/build-version.inc

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.glslang+=		glslang>=${SDK_VERSION}
.include "../../graphics/glslang/buildlink3.mk"
BUILDLINK_API_DEPENDS.spirv-headers+=	spirv-headers>=${SDK_VERSION}
.include "../../lang/python/tool.mk"
.include "../../parallel/spirv-headers/buildlink3.mk"
BUILDLINK_API_DEPENDS.spirv-tools+=	spirv-tools>=${SDK_VERSION}
.include "../../parallel/spirv-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
