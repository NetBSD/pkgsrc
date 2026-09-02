# $NetBSD: Makefile,v 1.1 2026/09/02 20:22:38 adam Exp $

.include "../../lang/llvm/version.mk"

PKGNAME=	libclc-${LLVM_VERSION}
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libclc.llvm.org/
COMMENT=	OpenCL library
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
GCC_REQD+=		7

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

PYTHON_FOR_BUILD_ONLY=	yes

PKGCONFIG_OVERRIDE+=	libclc.pc.in

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../parallel/spirv-tools/buildlink3.mk"
.include "../../parallel/spirv-llvm-translator/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
