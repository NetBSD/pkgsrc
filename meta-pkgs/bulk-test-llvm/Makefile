# $NetBSD: Makefile,v 1.6 2023/06/06 12:41:54 riastradh Exp $

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

TOOL_DEPENDS+=		clang-[0-9]*:../../lang/clang
TOOL_DEPENDS+=		creduce-[0-9]*:../../devel/creduce
TOOL_DEPENDS+=		cvise-[0-9]*:../../devel/cvise
TOOL_DEPENDS+=		firefox-[0-9]*:../../www/firefox
TOOL_DEPENDS+=		firefox-esr-[0-9]*:../../www/firefox-esr
TOOL_DEPENDS+=		include-what-you-use-[0-9]*:../../devel/include-what-you-use
TOOL_DEPENDS+=		polly-[0-9]*:../../devel/polly
TOOL_DEPENDS+=		qtcreator-[0-9]*:../../editors/qtcreator
TOOL_DEPENDS+=		libcxx-[0-9]*:../../lang/libcxx
TOOL_DEPENDS+=		libcxxabi-[0-9]*:../../lang/libcxxabi
TOOL_DEPENDS+=		libunwind-[0-9]*:../../lang/libunwind
TOOL_DEPENDS+=		lld-[0-9]*:../../devel/lld
TOOL_DEPENDS+=		lldb-[0-9]*:../../devel/lldb
TOOL_DEPENDS+=		mozjs78-[0-9]*:../../lang/mozjs78
TOOL_DEPENDS+=		opencl-clang-[0-9]*:../../parallel/opencl-clang
TOOL_DEPENDS+=		openmp-[0-9]*:../../parallel/openmp
TOOL_DEPENDS+=		pocl-[0-9]*:../../parallel/pocl
TOOL_DEPENDS+=		${PYPKGPREFIX}-llvmlite-[0-9]*:../../devel/py-llvmlite
TOOL_DEPENDS+=		rust-[0-9]*:../../lang/rust
TOOL_DEPENDS+=		seamonkey-[0-9]*:../../www/seamonkey
TOOL_DEPENDS+=		spirv-llvm-translator-[0-9]*:../../parallel/spirv-llvm-translator
TOOL_DEPENDS+=		thunderbird-[0-9]*:../../mail/thunderbird
TOOL_DEPENDS+=		woboq_codebrowser-[0-9]*:../../devel/woboq_codebrowser
TOOL_DEPENDS+=		zig-[0-9]*:../../lang/zig

.include "../../mk/bsd.pkg.mk"
