# $NetBSD: Makefile,v 1.4 2026/09/26 01:02:35 ktnb Exp $

DISTNAME=		slang-2026.18.3
PKGNAME=		shader-${DISTNAME}
CATEGORIES=		graphics lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=shader-slang/}
GITHUB_TAG=		v${PKGVERSION_NOREV}
GITHUB_PROJECT=		slang
GITHUB_SUBMODULES=	swiftlang swift-cmark 924936d0427cb25a61169739a7660230bffa6ea6 external/cmark
GITHUB_SUBMODULES+=	shader-slang  slang-rhi 079b75b54c49e6546fd611c9a91a25307c279668 external/slang-rhi
GITHUB_SUBMODULES+=	ocornut imgui 8936b58fe26e8c3da834b8f60b06511d537b4c63 external/imgui
DIST_SUBDIR=		slang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shader-slang/slang/
COMMENT=	Shading language that supports many targets
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/${DISTNAME}

# this requires lua54 just to build but doesn't allow an easy
# way to use the system.
LUA_COMMIT=		3fe7be956f23385aa1950dc31e2f25127ccfc0ea
LUA_DISTFILE=		lua-${LUA_COMMIT}.tar.gz
DISTFILES=		${DEFAULT_DISTFILES} ${LUA_DISTFILE}
SITES.${LUA_DISTFILE}=	-https://github.com/lua/lua/archive/${LUA_COMMIT}.tar.gz

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_PREFIX_PATH=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DSLANG_USE_SYSTEM_SPIRV_HEADERS=ON
CMAKE_CONFIGURE_ARGS+=	-DSLANG_USE_SYSTEM_SPIRV_TOOLS=ON
CMAKE_CONFIGURE_ARGS+=	-DSLANG_USE_SYSTEM_UNORDERED_DENSE=ON
CMAKE_CONFIGURE_ARGS+=	-DSLANG_USE_SYSTEM_VULKAN_HEADERS=ON
CMAKE_CONFIGURE_ARGS+=	-DSLANG_USE_SYSTEM_GLSLANG=ON
CMAKE_CONFIGURE_ARGS+=	-DSLANG_USE_SYSTEM_MINIZ=ON
CMAKE_CONFIGURE_ARGS+=	-DSLANG_USE_SYSTEM_LZ4=ON
CMAKE_CONFIGURE_ARGS+=	-DSLANG_OVERRIDE_LUA_PATH=${WRKDIR}/luadep
# GFX causes build to fail
CMAKE_CONFIGURE_ARGS+=	-DSLANG_ENABLE_GFX=OFF
CMAKE_CONFIGURE_ARGS+=	-DSLANG_ENABLE_SLANG_RHI=OFF
CMAKE_CONFIGURE_ARGS+=	-DSLANG_ENABLE_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DSLANG_ENABLE_EXAMPLES=OFF
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CMAKE_CONFIGURE_ARGS+=	-DSLANG_ENABLE_DXIL=OFF
BUILDLINK_PASSTHRU_RPATHDIRS+=	${WRKSRC}/cmake-pkgsrc-build
.endif

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/cmake-pkgsrc-build/generators/Release/lib:${WRKSRC}/cmake-pkgsrc-build/Release/lib

post-extract:
	${MKDIR} ${WRKDIR}/luadep
	${MV} ${WRKDIR}/lua-${LUA_COMMIT} ${WRKDIR}/luadep/lua


# install just mass installs everything, including the original
pre-install:
	${RM} ${WRKSRC}/include/slang.h.orig

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/miniz/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/unordered-dense/buildlink3.mk"
.include "../../graphics/glslang/buildlink3.mk"
CXXFLAGS+=    -I${BUILDLINK_PREFIX.glslang}/include/glslang
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../math/fast_float/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../parallel/spirv-headers/buildlink3.mk"
.include "../../parallel/spirv-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
