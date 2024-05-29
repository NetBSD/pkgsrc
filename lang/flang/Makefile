# $NetBSD: Makefile,v 1.5 2024/05/29 16:33:13 adam Exp $

PKGREVISION= 1
.include "../../lang/llvm/version.mk"

DISTNAME=	flang-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://flang.llvm.org/
COMMENT=	Fortran compiler targeting LLVM
LICENSE=	apache-2.0

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:run gmake
GCC_REQD+=		12

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DFLANG_INCLUDE_TESTS=OFF
CMAKE_ARGS+=	-DCLANG_DIR=${BUILDLINK_PREFIX.clang}/lib/cmake/clang
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=YES

REPLACE_BASH=	tools/f18/flang-to-external-fc.in

PLIST_VARS=	notdarwin
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
MAKE_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
.else
PLIST.notdarwin=	yes
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
.endif

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/mlir/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
