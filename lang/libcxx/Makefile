# $NetBSD: Makefile,v 1.18 2023/10/06 19:15:21 adam Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	libcxx-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libcxx.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	apache-2.0

# libcxx requires libcxxabi's cxxabi.h to build, but libcxxabi requires
# libcxx's includes to build, so we have this unholy extra distfiles thing
# in both of them to get them to build against each other without causing
# circular dependencies.  This must be kept in sync with libcxxabi/Makefile.
LIBCXXABI=	libcxxabi-${LLVM_VERSION}.src
EXTRA_DIST+=	${LIBCXXABI}${EXTRACT_SUFX}

SITES.${LIBCXXABI}${EXTRACT_SUFX}=	\
	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}

USE_CXX_FEATURES+=	c++20
USE_LANGUAGES=		c c++
SSP_SUPPORTED=		no
GCC_REQD+=		12

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DLIBCXX_CXX_ABI=system-libcxxabi
CMAKE_ARGS+=	-DLIBCXX_CXX_ABI_INCLUDE_PATHS=${WRKDIR}/${LIBCXXABI}/include
CMAKE_ARGS+=	-DLIBCXX_ENABLE_ABI_LINKER_SCRIPT=OFF
CMAKE_ARGS+=	-DLIBCXX_INCLUDE_BENCHMARKS=OFF

# avoid conflict with stddef.h
CXXFLAGS.NetBSD+=	-D__DEFINED_max_align_t=1

CXXFLAGS.SunOS+=	-D_LIBCPP_NO_ABI_TAG=1

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-[0-9].*} || ${CC_VERSION:Mgcc-10.*}
# Avoid GCC < 11 error https://github.com/llvm/llvm-project/issues/54018
CXXFLAGS+=		-std=c++17 -D_LIBCPP_STD_VER=17
.endif

post-extract:
	${LN} -f -s ${WRKDIR}/${LIBCXXABI} ${WRKDIR}/libcxxabi

.include "../../devel/cmake/build.mk"
.include "../../lang/libcxxabi/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
