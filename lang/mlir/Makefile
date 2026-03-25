# $NetBSD: Makefile,v 1.9 2026/03/25 22:56:27 wiz Exp $

.include "../../lang/llvm/version.mk"

PKGNAME=	mlir-${LLVM_VERSION}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mlir.llvm.org/
COMMENT=	Multi-Level Intermediate Representation
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DMLIR_INCLUDE_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DMLIR_INCLUDE_INTEGRATION_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DMLIR_INSTALL_AGGREGATE_OBJECTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DMLIR_BUILD_MLIR_C_DYLIB=ON
# Fix for: lib 'MLIR' not found.
# MLIR_LINK_MLIR_DYLIB defaults to LLVM_LINK_LLVM_DYLIB, but libMLIR.so is not built.
# https://github.com/llvm/llvm-project/issues/181584
CMAKE_CONFIGURE_ARGS+=	-DMLIR_LINK_MLIR_DYLIB=OFF

.include "../../devel/cmake/build.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
