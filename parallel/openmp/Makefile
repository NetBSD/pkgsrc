# $NetBSD: Makefile,v 1.3 2019/08/11 13:22:34 wiz Exp $

DISTNAME=	openmp-8.0.1.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=llvm/}
GITHUB_PROJECT=	llvm-project
GITHUB_RELEASE=	llvmorg-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openmp.llvm.org/
COMMENT=	Support for the OpenMP language
LICENSE=	modified-bsd

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
