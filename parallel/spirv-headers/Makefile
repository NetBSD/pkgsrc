# $NetBSD: Makefile,v 1.12 2026/04/13 13:19:10 kikadf Exp $

.include "../../graphics/vulkan-headers/Makefile.common"

DISTNAME=	SPIRV-Headers-${SDK_VERSION}
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-Headers
COMMENT=	Headers for translation between SPIR-V and LLVM IR
LICENSE=	mit

WRKSRC=		${WRKDIR}/SPIRV-Headers-${GITHUB_TAG}

PKGCONFIG_OVERRIDE+=	SPIRV-Headers.pc.in

pre-configure:
	${RM} -rf ${WRKSRC}/include/spirv/unified1/*.orig*

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
