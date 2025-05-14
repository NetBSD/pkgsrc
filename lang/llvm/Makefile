# $NetBSD: Makefile,v 1.111 2025/05/14 20:56:57 mef Exp $
#
# When updating this, please also update:
# devel/include-what-you-use
# devel/lld
# devel/lldb
# devel/polly
# lang/clang
# lang/clang-tools-extra
# lang/compiler-rt
# lang/libcxx
# lang/libcxxabi
# lang/libunwind
# lang/wasi-compiler-rt
# lang/wasi-libcxx
# parallel/openmp
#
# Do not update:
#   lang/libLLVM
# because pkgsrc provides multiple versions and lang/libLLVM is
# logically libLLVM4.
#
# Always update all */buildlink3.mk to require the latest stable release
# version in BUILDLINK_API_DEPENDS, as there is no backwards compatibility.

.include "version.mk"

DISTNAME=	llvm-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	lang devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure
LICENSE=	apache-2.0

POLICY_UPDATE_LIMITED=	abi

USE_CXX_FEATURES=	c++17 charconv
USE_LANGUAGES=		c c++
GCC_REQD+=		7
PYTHON_FOR_BUILD_ONLY=	no

NOT_FOR_PLATFORM+=	*-*-alpha
NOT_FOR_PLATFORM+=	*-*-vax

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_CXX_LINK_FLAGS=${LDFLAGS:Q}
CMAKE_CONFIGURE_ARGS+=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_BENCHMARKS=OFF
CMAKE_CONFIGURE_ARGS+=	-DLLVM_INSTALL_UTILS=ON
CMAKE_CONFIGURE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON
CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_RTTI=ON

CMAKE_CONFIGURE_ARGS.Darwin+=	-DCMAKE_LIBTOOL=/usr/bin/libtool

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

# XXX perl is not added as a tool as it does not seem to be required
REPLACE_PERL+=		utils/*.pl
REPLACE_PERL+=		utils/codegen-diff
REPLACE_PERL+=		utils/llvm-native-gxx

REPLACE_PYTHON+=	tools/opt-viewer/*.py
REPLACE_PYTHON+=	tools/sancov/*.py
REPLACE_PYTHON+=	utils/*.py
REPLACE_PYTHON+=	utils/Misc/zkill
REPLACE_PYTHON+=	utils/bisect
REPLACE_PYTHON+=	utils/clang-parse-diagnostics-file
REPLACE_PYTHON+=	utils/lit/tests/Inputs/googletest-format/DummySubDir/OneTest.py

TEST_TARGET=		check
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

# It may be that the Solaris linker is more strict here and they can be removed on
# all platforms.  Change this to a patch if verified.
SUBST_CLASSES.SunOS+=	linkmap
SUBST_STAGE.linkmap=	pre-configure
SUBST_FILES.linkmap+=	tools/remarks-shlib/Remarks.exports
SUBST_SED.linkmap=	-e '/^LLVM/d'

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
# Fix the runtime Python path.
SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-build
SUBST_FILES.python=	${CMAKE_BUILD_DIR}/bin/llvm-lit
SUBST_SED.python=	-e '1s,\#!.*python.*,\#!${PYTHONBIN},'
.endif

PLIST_VARS+=	notdylib
.if ${SHLIB_TYPE} != "dylib"
PLIST.notdylib=	yes
.endif

NOTDYLIBS=		LTO Remarks
.for libname in ${NOTDYLIBS}
PRINT_PLIST_AWK+=	/lib${libname}.${SHLIB_EXT}.${LLVM_MAJOR_VERSION}/ { gsub(/\.${SHLIB_EXT}\.${LLVM_MAJOR_VERSION}/, ".$${SHLIB_EXT}.$${LLVM_MAJOR_VERSION}"); print "$${PLIST.notdylib}" $$0; next }
.endfor
PRINT_PLIST_AWK+=	{ gsub(/\.${SHLIB_EXT}/, ".$${SHLIB_EXT}") }

# needs std::atomic with 64-bit CAS
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=	-march=i586
.endif

.if ${MACHINE_ARCH:Mpowerpc*}
# Needed to avoid "relocation truncated to fit: R_PPC_REL24"
CFLAGS+=	-mlongcall
CXXFLAGS+=	-mlongcall
.  if ${OPSYS} == "NetBSD"
.    if ${OPSYS_VERSION} >= 099917
# The -mno-pltseq option is not available in gcc7, but is needed for
# the above-mentioned relocation truncation issue in newer GCC
CFLAGS+=	-mno-pltseq
CXXFLAGS+=	-mno-pltseq
.    endif # (just drop for older NetBSD)
.  else # Not NetBSD
# Let's just insist on newer gcc -- untested.
CFLAGS+=	-mno-pltseq
CXXFLAGS+=	-mno-pltseq
.  endif
.endif

PLIST_SUBST+=	RELEASE_TYPE=${RELEASE_TYPE}

.if ${OPSYS} == "NetBSD"
CMAKE_CONFIGURE_ARGS+=	-DPKGSRC_LLVM_PTHREADLIB=-lpthread
.endif

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
TOOL_DEPENDS+=		${PKGNAME}:../../${PKGPATH}
CMAKE_CONFIGURE_ARGS+=	-DLLVM_TABLEGEN:STRING=${TOOLBASE:Q}/bin/llvm-tblgen
.endif

.include "options.mk"

# replacing config.guess is required even for cmake.
# It is used to detect correct LLVM_HOST_TRIPLE, e.g. for NetBSD/evbarm.
post-extract:
.for f in config.guess config.sub
	${CP} ../../mk/gnu-config/${f} ${WRKSRC}/cmake/${f}
.endfor

.include "../../devel/cmake/build.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
