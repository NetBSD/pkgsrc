# $NetBSD: Makefile,v 1.14 2025/09/23 13:00:27 tnn Exp $

# Note that parallel/spirv-headers must be kept in sync with what this
# package expects.
DISTNAME=	SPIRV-LLVM-Translator-19.1.7
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-LLVM-Translator
COMMENT=	Tool and library for translation between SPIR-V and LLVM IR
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++
GCC_REQD+=	7 # sync with llvm

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DLLVM_EXTERNAL_SPIRV_HEADERS_SOURCE_DIR=${PREFIX}/include/libLLVM

PKGCONFIG_OVERRIDE+=	LLVMSPIRVLib.pc.in

.include "../../devel/cmake/build.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../parallel/spirv-headers/buildlink3.mk"
.include "../../parallel/spirv-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
