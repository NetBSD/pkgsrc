# $NetBSD: Makefile,v 1.4 2021/11/23 20:55:44 wiz Exp $

DISTNAME=	SPIRV-LLVM-Translator-13.0.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-LLVM-Translator
COMMENT=	Tool and library for translation between SPIR-V and LLVM IR
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

GCC_REQD+=	5 # C++14

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DLLVM_EXTERNAL_SPIRV_HEADERS_SOURCE_DIR=${PREFIX}/include

PKGCONFIG_OVERRIDE+=	LLVMSPIRVLib.pc.in

.include "../../lang/llvm/buildlink3.mk"
.include "../../parallel/spirv-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
