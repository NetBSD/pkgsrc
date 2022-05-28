# $NetBSD: version.mk,v 1.8 2022/05/28 01:51:16 gutteridge Exp $
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

LLVM_VERSION=	13.0.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=llvm/}
GITHUB_PROJECT=	llvm-project
GITHUB_RELEASE=	llvmorg-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz
