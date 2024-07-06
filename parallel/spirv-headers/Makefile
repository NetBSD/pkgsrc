# $NetBSD: Makefile,v 1.6 2024/07/06 15:51:13 adam Exp $

# This version should be kept in sync with what
# parallel/spirv-llvm-translator's ${WRKSRC}/spirv-headers-tag.conf
# contains.
DISTNAME=	SPIRV-Headers-1.3.283.0
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_TAG=	vulkan-sdk-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-Headers
COMMENT=	Headers for translation between SPIR-V and LLVM IR
LICENSE=	mit

USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/SPIRV-Headers-${GITHUB_TAG}

PKGCONFIG_OVERRIDE+=	SPIRV-Headers.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
