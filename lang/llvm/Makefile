# $NetBSD: Makefile,v 1.16.2.1 2017/05/01 08:31:17 bsiegert Exp $
#
# when updating this, please also update:
# devel/include-what-you-use
# devel/lldb
# devel/polly
# lang/clang
# lang/clang-static-analyzer
# lang/libLLVM
# lang/libunwind

DISTNAME=	llvm-4.0.0.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
GCC_REQD+=		4.8
PYTHON_FOR_BUILD_ONLY=	yes

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++
CMAKE_ARGS+=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF
CMAKE_ARGS+=	-DLLVM_INSTALL_UTILS=ON
CMAKE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON

CMAKE_ARGS.Darwin+=	-DCMAKE_LIBTOOL=/usr/bin/libtool

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

# XXX perl is not added as a tool as it does not seem to be required
REPLACE_PERL+=		utils/GenLibDeps.pl
REPLACE_PERL+=		utils/UpdateCMakeLists.pl
REPLACE_PERL+=		utils/codegen-diff
REPLACE_PERL+=		utils/findsym.pl
REPLACE_PERL+=		utils/llvm-native-gxx
REPLACE_PERL+=		utils/test_debuginfo.pl

REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/cached/genk-timing.py
REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/cached/split-lib.py
REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/complete/genk-timing.py
REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/complete/split-lib.py
REPLACE_PYTHON+=	examples/Kaleidoscope/MCJIT/lazy/genk-timing.py
REPLACE_PYTHON+=	test/BugPoint/compile-custom.ll.py
REPLACE_PYTHON+=	test/tools/llvm-readobj/Inputs/relocs.py
REPLACE_PYTHON+=	utils/Misc/zkill
REPLACE_PYTHON+=	utils/Target/ARM/analyze-match-table.py
REPLACE_PYTHON+=	utils/bisect
REPLACE_PYTHON+=	utils/clang-parse-diagnostics-file
REPLACE_PYTHON+=	utils/create_ladder_graph.py
REPLACE_PYTHON+=	utils/git/find-rev
REPLACE_PYTHON+=	utils/lint/common_lint.py
REPLACE_PYTHON+=	utils/lint/cpp_lint.py
REPLACE_PYTHON+=	utils/lint/generic_lint.py
REPLACE_PYTHON+=	utils/lit/lit.py
REPLACE_PYTHON+=	utils/lit/lit/ProgressBar.py
REPLACE_PYTHON+=	utils/lit/lit/main.py
REPLACE_PYTHON+=	utils/lit/tests/Inputs/googletest-format/DummySubDir/OneTest
REPLACE_PYTHON+=	utils/llvm-build/llvm-build
REPLACE_PYTHON+=	utils/llvm-compilers-check
REPLACE_PYTHON+=	utils/llvm-lit/llvm-lit.in
REPLACE_PYTHON+=	utils/release/findRegressions-nightly.py
REPLACE_PYTHON+=	utils/release/findRegressions-simple.py
REPLACE_PYTHON+=	utils/schedcover.py
REPLACE_PYTHON+=	utils/shuffle_fuzz.py
REPLACE_PYTHON+=	utils/sort_includes.py
REPLACE_PYTHON+=	utils/testgen/mc-bundling-x86-gen.py
REPLACE_PYTHON+=	utils/update_llc_test_checks.py
REPLACE_PYTHON+=	utils/wciia.py

TEST_TARGET=		check
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

# It may be that the Solaris linker is more strict here and they can be removed on
# all platforms.  Change this to a patch if verified.
SUBST_CLASSES.SunOS+=	lto
SUBST_STAGE.lto=	pre-configure
SUBST_FILES.lto=	tools/lto/lto.exports
SUBST_SED.lto=		-e '/^LLVM/d'

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	notdylib
.if ${_OPSYS_SHLIB_TYPE} == "dylib"
SOEXT=		dylib
.else
SOEXT=		so
PLIST.notdylib=	yes
.endif
PLIST_SUBST+=	SOEXT=${SOEXT}

# At least LLVM 3.9.0 and subprojects don't correctly add C++11 flags
# automatically.
CXXFLAGS+=	-std=c++11

# needs std::atomic with 64-bit CAS
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=	-march=i586
.endif

.include "options.mk"

# replacing config.guess is required even for cmake.
# It is used to detect correct LLVM_HOST_TRIPLE, e.g. for NetBSD/evbarm.
post-extract:
	${RUN} mkdir -p ${WRKDIR}/build
.for f in config.guess config.sub
	cp ../../mk/gnu-config/${f} ${WRKSRC}/cmake/${f}
.endfor

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
