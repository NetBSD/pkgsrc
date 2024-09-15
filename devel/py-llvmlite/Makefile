# $NetBSD: Makefile,v 1.29 2024/09/15 10:46:16 wiz Exp $

DISTNAME=	llvmlite-0.43.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/llvmlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://llvmlite.readthedocs.io/
COMMENT=	Lightweight LLVM Python binding for writing JIT compilers
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

# Statically linking in a purpose-built LLVM as upstream urges to do.
# They support only a certain version of LLVM per release, and that
# with patches.
# TODO: As of 0.43.0, this supports llvm 15.
LLVM_VERSION=	14.0.6
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	llvm-${LLVM_VERSION}.src.tar.xz
DISTFILES+=	lld-${LLVM_VERSION}.src.tar.xz
DISTFILES+=	libunwind-${LLVM_VERSION}.src.tar.xz

LLVM_SITE=					https://github.com/llvm/llvm-project/releases/download/llvmorg-${LLVM_VERSION}/
SITES.llvm-${LLVM_VERSION}.src.tar.xz=		${LLVM_SITE}
SITES.lld-${LLVM_VERSION}.src.tar.xz=		${LLVM_SITE}
SITES.libunwind-${LLVM_VERSION}.src.tar.xz=	${LLVM_SITE}

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++14
# Just for LLVM build.
USE_TOOLS=		cmake

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
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_ASSERTIONS:BOOL=ON
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLINK_POLLY_INTO_TOOLS:BOOL=ON
# Don't really require libxml2. Turn it off explicitly to avoid accidentally linking to system libs
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_LIBXML2:BOOL=OFF
# Urgh, llvm *really* wants to link to ncurses / terminfo and we *really* do not want it to.
LLVM_CMAKE_CONFIGURE_ARGS+=	-DHAVE_TERMINFO_CURSES=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
# Sometimes these are reported as unused. Whatever.
LLVM_CMAKE_CONFIGURE_ARGS+=	-DHAVE_TERMINFO_NCURSES=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DHAVE_TERMINFO_NCURSESW=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DHAVE_TERMINFO_TERMINFO=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DHAVE_TERMINFO_TINFO=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DHAVE_TERMIOS_H=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DCLANG_ENABLE_LIBXML=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLIBOMP_INSTALL_ALIASES=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_ENABLE_RTTI=OFF
# Not sure if this should be adapted for pkgsrc.
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_TARGETS_TO_BUILD=all
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=WebAssembly
# for llvm-lit
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_UTILS=ON
# doesn't build without the rest of LLVM project
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_BENCHMARKS:BOOL=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_DOCS=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_EXAMPLES=OFF
LLVM_CMAKE_CONFIGURE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF

MAKE_ENV+=		LLVM_CONFIG=${WRKDIR}/llvm-inst/bin/llvm-config
# unable to pass LLVM bit-code files to linker
MAKE_ENV.NetBSD+=	CXX_FLTO_FLAGS=
MAKE_ENV.NetBSD+=	LD_FLTO_FLAGS=

# The llvm build detects lots of stuff outside the build sandbox ...
# a python it likes, git ... just hoping that this does not matter
# much for the static lib being used by llvmlite.

# sed: see https://github.com/numba/llvmlite/pull/1077
pre-configure:
	cd ${WRKDIR}/llvm-${LLVM_VERSION}.src && \
	  for f in ${FILESDIR}/llvm*.patch; do patch -Np2 < $$f; done
	${LN} -s llvm-${LLVM_VERSION}.src ${WRKDIR}/llvm
	${LN} -s lld-${LLVM_VERSION}.src ${WRKDIR}/lld
	${LN} -s libunwind-${LLVM_VERSION}.src ${WRKDIR}/libunwind
	cd ${WRKDIR} &&  mkdir build && cd build && \
	  cmake -G'Unix Makefiles' ${LLVM_CMAKE_CONFIGURE_ARGS} ../llvm && \
	  ${MAKE} -j${MAKE_JOBS} && \
	  ${MAKE} install
	${SED} -e 's/ -stdlib=libc++//' ${WRKSRC}/ffi/Makefile.freebsd > ${WRKSRC}/ffi/Makefile.netbsd

.include "../../mk/bsd.prefs.mk"
post-install:
.if ${OPSYS} == "Darwin"
	install_name_tool -id \
		${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib \
		${DESTDIR}${PREFIX}/${PYSITELIB}/llvmlite/binding/libllvmlite.dylib
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
