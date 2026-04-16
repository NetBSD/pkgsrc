# $NetBSD: inplace.mk,v 1.1 2026/04/16 06:36:45 wiz Exp $

# This Makefile fragment is intended for those times when py-llvmlite
# doesn't support the current pkgsrc llvm version.

# Statically linking in a purpose-built LLVM as upstream urges to do.
# They support only a certain version of LLVM per release, and that
# with patches.

LLVM_VERSION=	20.1.8
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	cmake-${LLVM_VERSION}.src.tar.xz
DISTFILES+=	llvm-${LLVM_VERSION}.src.tar.xz
DISTFILES+=	lld-${LLVM_VERSION}.src.tar.xz
DISTFILES+=	libunwind-${LLVM_VERSION}.src.tar.xz

LLVM_SITE=					https://github.com/llvm/llvm-project/releases/download/llvmorg-${LLVM_VERSION}/
SITES.cmake-${LLVM_VERSION}.src.tar.xz=		${LLVM_SITE}
SITES.llvm-${LLVM_VERSION}.src.tar.xz=		${LLVM_SITE}
SITES.lld-${LLVM_VERSION}.src.tar.xz=		${LLVM_SITE}
SITES.libunwind-${LLVM_VERSION}.src.tar.xz=	${LLVM_SITE}

# Just for LLVM build.
USE_TOOLS+=		cmake patch

# See
# https://github.com/numba/llvmlite/blob/main/conda-recipes/llvmdev/build.sh
# for the procedure. This is what
# https://llvmlite.readthedocs.io/en/latest/admin-guide/install.html
# points to. Need to match up this to the correct llvmlite release, as
# they do not include this in the tarball. Python people think building
# stuff from source is hard and keep it so:-/
# I kept some upstream comments inline.

LLVM_CMAKE_CONFIGURE_ARGS=	-DCMAKE_INSTALL_PREFIX=${WRKDIR}/llvm-inst
LLVM_CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_PROJECTS:STRING=lld
# We explicitly want static linking.
LLVM_CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_BUILD_STATIC:BOOL=ON
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLINK_POLLY_INTO_TOOLS:BOOL=ON
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_FFI=ON

# Urgh, llvm *really* wants to link to ncurses / terminfo and we *really* do not want it to.
LLVM_CMAKE_CONFIGURE_ARGS+=	-DHAVE_TERMINFO_CURSES=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_LIBEDIT=OFF
# Don't really require libxml2. Turn it off explicitly to avoid accidentally linking to system libs
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_LIBXML2:BOOL=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_ZSTD:BOOL=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_Z3_SOLVER=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_RTTI=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_ASSERTIONS:BOOL=ON
# Not sure if this should be adapted for pkgsrc.
#LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_TARGETS_TO_BUILD=all
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=WebAssembly
# for llvm-lit
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_UTILS=ON
# doesn't build without the rest of LLVM project
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_BENCHMARKS:BOOL=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_DOCS=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_EXAMPLES=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_GO_TESTS=OFF
# static build, so should be unneeded, and avoids error linking tblgen
LLVM_CMAKE_CONFIGURE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=TRUE

#MAKE_ENV+=		LLVM_CONFIG=${WRKDIR}/llvm-inst/bin/llvm-config
MAKE_ENV+=		LLVM_DIR=${WRKDIR}/llvm-inst
# unable to pass LLVM bit-code files to linker
MAKE_ENV.NetBSD+=	CXX_FLTO_FLAGS=
MAKE_ENV.NetBSD+=	LD_FLTO_FLAGS=

# The llvm build detects lots of stuff outside the build sandbox ...
# a python it likes, git ... just hoping that this does not matter
# much for the static lib being used by llvmlite.

# sed: see https://github.com/numba/llvmlite/pull/1077
pre-configure: llvm-configure
.PHONY: llvm-configure
llvm-configure:
#	cd ${WRKDIR}/llvm-${LLVM_VERSION}.src && \
#	  for f in ${FILESDIR}/llvm*.patch; do patch -Np2 < $$f; done
	${LN} -s cmake-${LLVM_VERSION}.src ${WRKDIR}/cmake
	${LN} -s llvm-${LLVM_VERSION}.src ${WRKDIR}/llvm
	${LN} -s llvm-${LLVM_VERSION}.src/cmake ${WRKDIR}/cmake
	${LN} -s lld-${LLVM_VERSION}.src ${WRKDIR}/lld
	${LN} -s libunwind-${LLVM_VERSION}.src ${WRKDIR}/libunwind
	cd ${WRKDIR} &&  mkdir build && cd build && \
	  cmake -G'Unix Makefiles' ${LLVM_CMAKE_CONFIGURE_ARGS} ../llvm && \
	  ${MAKE} ${_MAKE_JOBS} && \
	  ${MAKE} install

.include "../../devel/libffi/buildlink3.mk"
