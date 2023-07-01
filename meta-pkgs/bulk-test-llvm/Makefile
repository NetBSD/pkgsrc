# $NetBSD: Makefile,v 1.7 2023/07/01 14:19:45 nia Exp $

DISTNAME=	bulk-test-llvm-20211207
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nia@NetBSD.org
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

DEPENDS+=	clang-[0-9]*:../../lang/clang
DEPENDS+=	creduce-[0-9]*:../../devel/creduce
DEPENDS+=	cvise-[0-9]*:../../devel/cvise
DEPENDS+=	firefox-[0-9]*:../../www/firefox
DEPENDS+=	firefox-esr-[0-9]*:../../www/firefox-esr
DEPENDS+=	include-what-you-use-[0-9]*:../../devel/include-what-you-use
DEPENDS+=	polly-[0-9]*:../../devel/polly
DEPENDS+=	qtcreator-[0-9]*:../../editors/qtcreator
DEPENDS+=	libcxx-[0-9]*:../../lang/libcxx
DEPENDS+=	libcxxabi-[0-9]*:../../lang/libcxxabi
DEPENDS+=	libunwind-[0-9]*:../../lang/libunwind
DEPENDS+=	lld-[0-9]*:../../devel/lld
DEPENDS+=	lldb-[0-9]*:../../devel/lldb
DEPENDS+=	mozjs78-[0-9]*:../../lang/mozjs78
DEPENDS+=	opencl-clang-[0-9]*:../../parallel/opencl-clang
DEPENDS+=	openmp-[0-9]*:../../parallel/openmp
DEPENDS+=	pocl-[0-9]*:../../parallel/pocl
DEPENDS+=	${PYPKGPREFIX}-llvmlite-[0-9]*:../../devel/py-llvmlite
DEPENDS+=	rust-[0-9]*:../../lang/rust
DEPENDS+=	seamonkey-[0-9]*:../../www/seamonkey
DEPENDS+=	spirv-llvm-translator-[0-9]*:../../parallel/spirv-llvm-translator
DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
DEPENDS+=	woboq_codebrowser-[0-9]*:../../devel/woboq_codebrowser
DEPENDS+=	zig-[0-9]*:../../lang/zig

.include "../../mk/bsd.pkg.mk"
