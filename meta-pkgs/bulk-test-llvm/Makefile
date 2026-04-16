# $NetBSD: Makefile,v 1.17 2026/04/16 06:40:01 wiz Exp $

DISTNAME=	bulk-test-llvm-20260410
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for testing LLVM

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# All of these (primarily leaf) packages depend on LLVM.
# Feel free to add one if you care about it not breaking.
# The current list is mostly arbitrary, resulting from a grep of the
# pkgsrc tree.

.include "../../lang/python/pyversion.mk"

# LLVM project
DEPENDS+=	clang-[0-9]*:../../lang/clang
DEPENDS+=	clang-tools-extra-[0-9]*:../../lang/clang-tools-extra
DEPENDS+=	compiler-rt-[0-9]*:../../lang/compiler-rt
DEPENDS+=	flang-[0-9]*:../../lang/flang
DEPENDS+=	libcxx-[0-9]*:../../lang/libcxx
DEPENDS+=	libcxxabi-[0-9]*:../../lang/libcxxabi
DEPENDS+=	libunwind-[0-9]*:../../lang/libunwind
DEPENDS+=	lld-[0-9]*:../../devel/lld
DEPENDS+=	lldb-[0-9]*:../../devel/lldb
DEPENDS+=	mlir-[0-9]*:../../lang/mlir
DEPENDS+=	openmp-[0-9]*:../../parallel/openmp
DEPENDS+=	polly-[0-9]*:../../devel/polly

#DEPENDS+=	ghdl-[0-9]*:../../cad/ghdl
DEPENDS+=	ccls-[0-9]*:../../devel/ccls
DEPENDS+=	cvise-[0-9]*:../../devel/cvise
DEPENDS+=	firefox-[0-9]*:../../www/firefox
DEPENDS+=	firefox-esr-[0-9]*:../../www/firefox-esr
DEPENDS+=	include-what-you-use-[0-9]*:../../devel/include-what-you-use
DEPENDS+=	mozjs78-[0-9]*:../../lang/mozjs78
DEPENDS+=	opencl-clang-[0-9]*:../../parallel/opencl-clang
DEPENDS+=	pocl-[0-9]*:../../parallel/pocl
DEPENDS+=	${PYPKGPREFIX}-llvmlite-[0-9]*:../../devel/py-llvmlite
DEPENDS+=	qtcreator-[0-9]*:../../editors/qtcreator
DEPENDS+=	rust-[0-9]*:../../lang/rust
DEPENDS+=	seamonkey-[0-9]*:../../www/seamonkey
DEPENDS+=	spirv-llvm-translator-[0-9]*:../../parallel/spirv-llvm-translator
DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
DEPENDS+=	woboq_codebrowser-[0-9]*:../../devel/woboq_codebrowser
DEPENDS+=	zig-[0-9]*:../../lang/zig

.include "../../mk/bsd.pkg.mk"
