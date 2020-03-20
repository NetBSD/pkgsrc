# $NetBSD: Makefile,v 1.36 2020/03/20 17:51:57 nia Exp $

DISTNAME=	llvm-9.0.1.src
PKGNAME=	${DISTNAME:S/llvm/libLLVM/:S/.src//}
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvm.org/
COMMENT=	Low Level Virtual Machine shared library
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		5
PYTHON_FOR_BUILD_ONLY=	yes

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=${CXX:Q}
CMAKE_ARGS+=	-DCMAKE_CXX_LINK_FLAGS=${LDFLAGS:Q}
CMAKE_ARGS+=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_INSTALL_UTILS=OFF
CMAKE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBXML2=OFF
CMAKE_ARGS+=	-DLLVM_BUILD_UTILS=OFF
CMAKE_ARGS+=	-DLLVM_INCLUDE_BENCHMARKS=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_RTTI=ON
CMAKE_ARGS+=	-DCMAKE_EXE_LINKER_FLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib/libLLVM

CMAKE_ARGS.Darwin+=	-DCMAKE_LIBTOOL=/usr/bin/libtool

.for tool in	bugpoint bugpoint_passes dsymutil gold llc lli llvm_ar	\
	llvm_as llvm_as_fuzzer llvm_bcanalyzer llvm_c_test llvm_cat	\
	llvm_cfi_verify llvm_cov llvm_cvtres llvm_cxxdump llvm_cxxfilt	\
	llvm_cxxmap llvm_diff llvm_dis llvm_dwarfdump llvm_dwp		\
	llvm_elfabi llvm_exegesis llvm_extract llvm_go llvm_isel_fuzzer	\
	llvm_itanium_demangle_fuzzer llvm_jitlink llvm_jitlistener	\
	llvm_link llvm_lipo llvm_lto llvm_lto2 llvm_mc			\
	llvm_mc_assemble_fuzzer llvm_mc_disassemble_fuzzer llvm_mca	\
	llvm_microsoft_demangle_fuzzer llvm_modextract llvm_mt llvm_nm	\
	llvm_objcopy llvm_objdump llvm_opt_fuzzer llvm_opt_report	\
	llvm_pdbutil llvm_profdata llvm_rc llvm_readobj llvm_rtdyld	\
	llvm_size llvm_special_case_list_fuzzer llvm_split llvm_stress	\
	llvm_strings llvm_symbolizer llvm_undname llvm_xray		\
	llvm_yaml_numeric_parser_fuzzer lto msbuild obj2yaml		\
	opt opt_viewer remarks_shlib sancov sanstats			\
	verify_uselistorder xcode_toolchain yaml2obj

CMAKE_ARGS+=	-DLLVM_TOOL_${tool:tu}_BUILD=OFF
.endfor

SUBST_CLASSES+=		fix-cnf
SUBST_STAGE.fix-cnf=	pre-configure
SUBST_MESSAGE.fix-cnf=	Fixing llvm-config paths
SUBST_FILES.fix-cnf=	tools/llvm-config/llvm-config.cpp
SUBST_VARS.fix-cnf=	PREFIX LLVM_MAJOR_MINOR COMPILER_RPATH_FLAG

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
REPLACE_PYTHON+=	utils/git/find-rev
REPLACE_PYTHON+=	utils/lit/tests/Inputs/googletest-format/DummySubDir/OneTest
REPLACE_PYTHON+=	utils/llvm-build/llvm-build
REPLACE_PYTHON+=	utils/llvm-compilers-check
REPLACE_PYTHON+=	utils/llvm-lit/llvm-lit.in

TEST_TARGET=		check
TEST_ENV+=		LD_LIBRARY_PATH=${WRKDIR}/build/lib

.include "../../mk/bsd.prefs.mk"

# 7.0.1 -> 7.0
#LLVM_MAJOR_MINOR=	${PKGVERSION_NOREV:C/^([0-9]+\.[0-9]+)\..*$/\1/}
# 7.0.1 -> 7
LLVM_MAJOR_MINOR=	${PKGVERSION_NOREV:C/^([0-9]+).*$/\1/}
PLIST_SUBST+=		LLVM_MAJOR_MINOR=${LLVM_MAJOR_MINOR}

PLIST_VARS+=	notdylib
.if ${SHLIB_TYPE} == "dylib"
SOEXT=		dylib
LLVM_LIBNAME=	libLLVM.${SOEXT}
.else
SOEXT=		so
LLVM_LIBNAME=	libLLVM-${LLVM_MAJOR_MINOR}.${SOEXT}
PLIST.notdylib=	yes
.endif
PLIST_SUBST+=	SOEXT=${SOEXT}
PLIST_SUBST+=	LLVM_LIBNAME=${LLVM_LIBNAME}

.include "options.mk"

# needs std::atomic with 64-bit CAS
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=	-march=i586
.endif

# replacing config.guess is required even for cmake.
# It is used to detect correct LLVM_HOST_TRIPLE, e.g. for NetBSD/evbarm.
post-extract:
	${RUN} mkdir -p ${WRKDIR}/build
.for f in config.guess config.sub
	cp ../../mk/gnu-config/${f} ${WRKSRC}/cmake/${f}
.endfor

post-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/libLLVM
	${INSTALL_LIB} ${WRKDIR}/build/lib/${LLVM_LIBNAME}	\
		${DESTDIR}${PREFIX}/lib/libLLVM/${LLVM_LIBNAME}
.if ${OPSYS} == "Darwin"
	install_name_tool -id	\
		${PREFIX}/lib/libLLVM/${LLVM_LIBNAME}	\
		${DESTDIR}${PREFIX}/lib/libLLVM/${LLVM_LIBNAME}
.else
	${LN} -sf ${LLVM_LIBNAME}	\
		${DESTDIR}${PREFIX}/lib/libLLVM/libLLVM.${SOEXT}
	${LN} -sf ${LLVM_LIBNAME}	\
		${DESTDIR}${PREFIX}/lib/libLLVM/libLLVM-${PKGVERSION_NOREV}.${SOEXT}
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
