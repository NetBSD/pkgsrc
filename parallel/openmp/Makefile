# $NetBSD: Makefile,v 1.17 2023/08/02 19:27:31 nia Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	openmp-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openmp.llvm.org/
COMMENT=	Support for the OpenMP language
LICENSE=	apache-2.0

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
USE_TOOLS+=		perl pkg-config

USE_CXX_FEATURES+=	c++14

# Uses alloca, cannot use standard C++ on NetBSD.
FORCE_CXX_STD=		gnu++14

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DOPENMP_ENABLE_LIBOMPTARGET=OFF
CMAKE_ARGS+=	-DOPENMP_ENABLE_OMPT_TOOLS=OFF

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
