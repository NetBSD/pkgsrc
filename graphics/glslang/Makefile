# $NetBSD: Makefile,v 1.1 2026/04/13 14:38:43 kikadf Exp $

.include "../../graphics/vulkan-headers/Makefile.common"

DISTNAME=	glslang-${SDK_VERSION}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/glslang/
COMMENT=	Front end for GLSL/ESSL, HLSL (partial) and SPIR-V generator
LICENSE=	modified-bsd AND 2-clause-bsd AND mit AND apache-2.0 AND gnu-gpl-v3

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

CMAKE_CONFIGURE_ARGS+=	-DALLOW_EXTERNAL_SPIRV_TOOLS=ON

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../parallel/spirv-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
