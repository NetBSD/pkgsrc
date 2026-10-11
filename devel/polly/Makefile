# $NetBSD: Makefile,v 1.29 2026/10/11 16:02:18 wiz Exp $

PKGREVISION= 1
.include "../../lang/llvm/version.mk"

PKGNAME=	polly-${LLVM_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://polly.llvm.org/
COMMENT=	Polyhedral optimizations for LLVM
LICENSE=	apache-2.0

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm

USE_CXX_FEATURES=	c++17
FORCE_CXX_STD=		c++17
USE_LANGUAGES=		c c++
GCC_REQD+=		4.8

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

.include "../../devel/cmake/build.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
