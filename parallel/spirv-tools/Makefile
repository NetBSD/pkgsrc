# $NetBSD: Makefile,v 1.7 2026/08/07 10:42:20 kikadf Exp $

.include "../../graphics/vulkan-headers/Makefile.common"

DISTNAME=	SPIRV-Tools-${SDK_VERSION}
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-Tools/
COMMENT=	API and commands for processing SPIR-V modules
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	cmake/SPIRV-Tools-shared.pc.in
PKGCONFIG_OVERRIDE+=	cmake/SPIRV-Tools.pc.in

WRKSRC=		${WRKDIR}/SPIRV-Tools-${GITHUB_TAG}

REPLACE_SH+=	tools/lesspipe/spirv-lesspipe.sh

CFLAGS+=	-Wno-error=array-bounds

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DSPIRV-Headers_SOURCE_DIR=${BUILDLINK_PREFIX.spirv-headers}

.include "../../devel/cmake/build.mk"

.include "../../lang/python/tool.mk"
BUILDLINK_API_DEPENDS.spirv-headers+=	spirv-headers>=${SDK_VERSION}
.include "../../parallel/spirv-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
