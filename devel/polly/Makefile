# $NetBSD: Makefile,v 1.6 2017/07/11 19:47:37 adam Exp $

DISTNAME=	polly-4.0.1.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://polly.llvm.org/
COMMENT=	Polyhedral optimizations for LLVM
LICENSE=	modified-bsd

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		4.8

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

DEPENDS+=	llvm-${PKGVERSION_NOREV}{,nb*}:../../lang/llvm
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
