# $NetBSD: version.mk,v 1.5 2021/07/12 18:41:02 adam Exp $
# used by devel/lld
# used by devel/lldb
# used by devel/polly
# used by lang/clang
# used by lang/clang-tools-extra
# used by lang/compiler-rt
# used by lang/libcxx
# used by lang/libcxxabi
# used by lang/libunwind
# used by parallel/openmp

LLVM_VERSION=	12.0.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=llvm/}
GITHUB_PROJECT=	llvm-project
GITHUB_RELEASE=	llvmorg-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz
