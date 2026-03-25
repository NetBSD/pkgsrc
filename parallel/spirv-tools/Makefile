# $NetBSD: Makefile,v 1.5 2026/03/25 23:01:21 wiz Exp $

DISTNAME=	SPIRV-Tools-2025.5
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-Tools/
COMMENT=	API and commands for processing SPIR-V modules
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	cmake/SPIRV-Tools-shared.pc.in
PKGCONFIG_OVERRIDE+=	cmake/SPIRV-Tools.pc.in

WRKSRC=		${WRKDIR}/${DISTNAME}

REPLACE_SH+=	tools/lesspipe/spirv-lesspipe.sh

CFLAGS+=	-Wno-error=array-bounds

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DSPIRV-Headers_SOURCE_DIR=${BUILDLINK_PREFIX.spirv-headers}

.include "../../devel/cmake/build.mk"

.include "../../lang/python/tool.mk"
.include "../../parallel/spirv-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
