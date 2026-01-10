# $NetBSD: Makefile,v 1.8 2026/01/10 07:48:59 wiz Exp $

PKGREVISION= 1
.include "../../lang/llvm/version.mk"

DISTNAME=	mlir-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mlir.llvm.org/
COMMENT=	Multi-Level Intermediate Representation
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DMLIR_INSTALL_AGGREGATE_OBJECTS=NO
CMAKE_CONFIGURE_ARGS+=	-DMLIR_BUILD_MLIR_C_DYLIB=YES

.include "../../devel/cmake/build.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
