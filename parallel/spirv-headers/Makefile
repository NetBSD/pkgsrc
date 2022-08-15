# $NetBSD: Makefile,v 1.2 2022/08/15 20:39:21 tnn Exp $

# This version should be kept in sync with what
# parallel/spirv-llvm-translator's ${WRKSRC}/spirv-headers-tag.conf
# contains.
DISTNAME=	SPIRV-Headers-1.3.216.0
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_TAG=	sdk-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-Headers
COMMENT=	Headers for translation between SPIR-V and LLVM IR
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/SPIRV-Headers-${GITHUB_TAG}

PKGCONFIG_OVERRIDE+=	SPIRV-Headers.pc.in

.include "../../mk/bsd.pkg.mk"
