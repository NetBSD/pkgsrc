# $NetBSD: Makefile,v 1.10 2025/10/04 12:07:45 tnn Exp $

# This version should be kept in sync with what
# parallel/spirv-llvm-translator's ${WRKSRC}/spirv-headers-tag.conf
# contains.
DISTNAME=	SPIRV-Headers-1.4.321.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_TAG=	vulkan-sdk-${PKGVERSION_NOREV}

PATCHFILES=		9e3836d7d6023843a72ecd3fbf3f09b1b6747a9e.patch
PATCHFILES+=		1de2e410ae8b5f7276afcfd9f3401a1c4e2cb2d7.patch
PATCH_DIST_STRIP=	-p1
SITES.9e3836d7d6023843a72ecd3fbf3f09b1b6747a9e.patch=	\
	https://github.com/KhronosGroup/SPIRV-Headers/commit/
SITES.1de2e410ae8b5f7276afcfd9f3401a1c4e2cb2d7.patch=	\
	https://github.com/KhronosGroup/SPIRV-Headers/commit/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-Headers
COMMENT=	Headers for translation between SPIR-V and LLVM IR
LICENSE=	mit

USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/SPIRV-Headers-${GITHUB_TAG}

PKGCONFIG_OVERRIDE+=	SPIRV-Headers.pc.in

pre-configure:
	${RM} -rf ${WRKSRC}/include/spirv/unified1/*.orig*

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
