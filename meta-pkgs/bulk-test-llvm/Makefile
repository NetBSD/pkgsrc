# $NetBSD: Makefile,v 1.4 2022/06/30 11:18:37 nia Exp $

DISTNAME=	bulk-test-llvm-20211120
PKGREVISION=	1
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

BUILD_DEPENDS+=		clang-[0-9]*:../../lang/clang
BUILD_DEPENDS+=		creduce-[0-9]*:../../devel/creduce
BUILD_DEPENDS+=		cvise-[0-9]*:../../devel/cvise
BUILD_DEPENDS+=		firefox-[0-9]*:../../www/firefox
BUILD_DEPENDS+=		firefox-esr-[0-9]*:../../www/firefox-esr
BUILD_DEPENDS+=		include-what-you-use-[0-9]*:../../devel/include-what-you-use
BUILD_DEPENDS+=		polly-[0-9]*:../../devel/polly
BUILD_DEPENDS+=		qtcreator-[0-9]*:../../editors/qtcreator
BUILD_DEPENDS+=		libcxx-[0-9]*:../../lang/libcxx
BUILD_DEPENDS+=		libcxxabi-[0-9]*:../../lang/libcxxabi
BUILD_DEPENDS+=		libunwind-[0-9]*:../../lang/libunwind
BUILD_DEPENDS+=		lld-[0-9]*:../../devel/lld
BUILD_DEPENDS+=		lldb-[0-9]*:../../devel/lldb
BUILD_DEPENDS+=		mozjs78-[0-9]*:../../lang/mozjs78
BUILD_DEPENDS+=		opencl-clang-[0-9]*:../../parallel/opencl-clang
BUILD_DEPENDS+=		openmp-[0-9]*:../../parallel/openmp
BUILD_DEPENDS+=		pocl-[0-9]*:../../parallel/pocl
BUILD_DEPENDS+=		${PYPKGPREFIX}-llvmlite-[0-9]*:../../devel/py-llvmlite
BUILD_DEPENDS+=		rust-[0-9]*:../../lang/rust
BUILD_DEPENDS+=		seamonkey-[0-9]*:../../www/seamonkey
BUILD_DEPENDS+=		spirv-llvm-translator-[0-9]*:../../parallel/spirv-llvm-translator
BUILD_DEPENDS+=		thunderbird-[0-9]*:../../mail/thunderbird
BUILD_DEPENDS+=		zig-[0-9]*:../../lang/zig

.include "../../mk/bsd.pkg.mk"
