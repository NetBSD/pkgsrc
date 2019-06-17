# $NetBSD: Makefile,v 1.1 2019/06/17 16:35:44 adam Exp $

DISTNAME=	openmp-8.0.0.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openmp.llvm.org/
COMMENT=	Support for the OpenMP language
LICENSE=	modified-bsd

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
USE_TOOLS+=		perl pkg-config
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DOPENMP_ENABLE_LIBOMPTARGET=OFF

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
