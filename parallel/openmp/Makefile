# $NetBSD: Makefile,v 1.12 2022/06/28 11:35:24 wiz Exp $

PKGREVISION= 1
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

USE_LANGUAGES=		c c++14
USE_CMAKE=		yes
USE_TOOLS+=		perl pkg-config
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DOPENMP_ENABLE_LIBOMPTARGET=OFF
CMAKE_ARGS+=	-DOPENMP_ENABLE_OMPT_TOOLS=OFF

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
