# $NetBSD: Makefile,v 1.3 2021/07/24 11:00:13 nia Exp $

DISTNAME=	SPIRV-LLVM-Translator-v12.0.0
PKGNAME=	${DISTNAME:tl:S/-v/-/1}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KhronosGroup/}
GITHUB_PROJECT=	SPIRV-LLVM-Translator
GITHUB_TAG=	${DISTNAME:S/SPIRV-LLVM-Translator-//1}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KhronosGroup/SPIRV-LLVM-Translator
COMMENT=	Tool and library for translation between SPIR-V and LLVM IR
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

GCC_REQD+=	5 # C++14

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

PKGCONFIG_OVERRIDE+=	LLVMSPIRVLib.pc.in

.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
