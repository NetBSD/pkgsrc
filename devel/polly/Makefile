# $NetBSD: Makefile,v 1.20 2023/07/09 14:48:40 nia Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	polly-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://polly.llvm.org/
COMMENT=	Polyhedral optimizations for LLVM
LICENSE=	apache-2.0

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++14
USE_CMAKE=		yes
GCC_REQD+=		5

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
