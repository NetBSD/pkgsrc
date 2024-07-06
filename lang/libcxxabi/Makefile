# $NetBSD: Makefile,v 1.20 2024/07/06 15:45:06 adam Exp $

.include "../../lang/llvm/version.mk"

DISTNAME=	libcxxabi-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libcxxabi.llvm.org/
COMMENT=	C++ Standard Library
LICENSE=	apache-2.0

# libcxx requires libcxxabi's cxxabi.h to build, but libcxxabi requires
# libcxx's includes to build, so we have this unholy extra distfiles thing
# in both of them to get them to build against each other without causing
# circular dependencies.  This must be kept in sync with libcxxabi/Makefile.
LIBCXX=		libcxx-${LLVM_VERSION}.src
EXTRA_DIST+=	${LIBCXX}${EXTRACT_SUFX}

SITES.${LIBCXX}${EXTRACT_SUFX}=	\
	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
SSP_SUPPORTED=		no
GCC_REQD+=		13	# must be in sync with libcxx

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
# "LIBCXXABI_USE_LLVM_UNWINDER is set to ON, but libunwind is not specified in LLVM_ENABLE_RUNTIMES."
#CMAKE_ARGS+=	-DLLVM_ENABLE_RUNTIMES=libunwind
CMAKE_ARGS+=	-DLIBCXXABI_USE_LLVM_UNWINDER=OFF

# avoid conflict with stddef.h
CXXFLAGS.NetBSD+=	-D__DEFINED_max_align_t=1

.include "../../mk/compiler.mk"

.if ${CC_VERSION:Mgcc-[0-9].*} || ${CC_VERSION:Mgcc-10.*}
# Avoid GCC < 11 error https://github.com/llvm/llvm-project/issues/54018
CXXFLAGS+=	-std=c++17 -D_LIBCPP_STD_VER=17
.endif

# IMPORTANT: copy __config_site from partial build of libcxx.
post-extract:
	${LN} -f -s ${WRKDIR}/${LIBCXX} ${WRKDIR}/libcxx
	${CP} ${FILESDIR}/__assertion_handler ${FILESDIR}/__config_site \
		${WRKDIR}/${LIBCXX}/include/

.include "../../devel/cmake/build.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
