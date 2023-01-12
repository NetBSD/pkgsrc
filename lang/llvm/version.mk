# $NetBSD: version.mk,v 1.14 2023/01/12 19:32:53 adam Exp $
# used by devel/lld
# used by devel/lldb
# used by devel/polly
# used by lang/clang
# used by lang/clang-tools-extra
# used by lang/compiler-rt
# used by lang/libcxx
# used by lang/libcxxabi
# used by lang/libunwind
# used by lang/wasi-compiler-rt
# used by lang/wasi-libcxx
# used by parallel/openmp

LLVM_VERSION=	15.0.7
MASTER_SITES=	${MASTER_SITE_GITHUB:=llvm/}
GITHUB_PROJECT=	llvm-project
GITHUB_RELEASE=	llvmorg-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

LLVM_MAJOR_VERSION=	${LLVM_VERSION:tu:C/\\.[[:digit:]\.]*//}

# As of v15.0.0 llvm requires cmake source code to build
CMAKE_DIST=	cmake-${LLVM_VERSION}.src
EXTRA_DIST+=	${CMAKE_DIST}${EXTRACT_SUFX}
SITES.${CMAKE_DIST}${EXTRACT_SUFX}=	\
		${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}
DISTFILES=	${DEFAULT_DISTFILES} ${EXTRA_DIST}

.PHONY: llvm-cmake-modules
post-extract: llvm-cmake-modules
llvm-cmake-modules:
	${LN} -f -s ${WRKDIR}/${CMAKE_DIST} ${WRKDIR}/cmake
