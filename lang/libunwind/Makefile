# $NetBSD: Makefile,v 1.27 2022/08/13 09:00:23 tnn Exp $

.include "../../lang/llvm/version.mk"
PKGREVISION=	1

DISTNAME=	libunwind-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://libunwind.llvm.org/
COMMENT=	LLVM libunwind
LICENSE=	apache-2.0

# libunwind requires llvm and libcxx source code to build
LIBCXX=		libcxx-${LLVM_VERSION}.src
LLVMDIST=	llvm-${LLVM_VERSION}.src
EXTRA_DIST=	${LIBCXX}${EXTRACT_SUFX} ${LLVMDIST}${EXTRACT_SUFX}

SITES.${LIBCXX}${EXTRACT_SUFX}=	\
	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}
SITES.${LLLVMDIST}${EXTRACT_SUFX}=	\
	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}

DISTFILES=	${DEFAULT_DISTFILES} ${EXTRA_DIST}

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	${WRKSRC}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
USE_TOOLS+=		pax
SSP_SUPPORTED=		no

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}

INSTALLATION_DIRS=	include

post-extract:
	${MKDIR} ${WRKSRC}/build
	${LN} -f -s ${WRKDIR}/${LIBCXX} ${WRKDIR}/libcxx
	${LN} -f -s ${WRKDIR}/${LLVMDIST} ${WRKDIR}/llvm

post-install:
	cd ${WRKSRC}/include && ${PAX} -rw . ${DESTDIR}${PREFIX}/include

BUILDLINK_DEPMETHOD.llvm=	build
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
