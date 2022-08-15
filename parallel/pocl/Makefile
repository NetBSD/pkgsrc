# $NetBSD: Makefile,v 1.9 2022/08/15 19:21:21 wiz Exp $

DISTNAME=	pocl-1.8
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	http://portablecl.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://portablecl.org/
COMMENT=	Portable implementation of the OpenCL standard
LICENSE=	mit

BROKEN=		"version 1.8 does not support llvm 14, please update this to 3.0"

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TEST_TARGET=	check

# C++11
GCC_REQD+=	4.7

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR="lib"
CMAKE_ARGS+=	-DPOCL_INSTALL_ICD_VENDORDIR="${PREFIX}/share/examples/OpenCL/vendors"
CMAKE_ARGS+=	-DKERNELLIB_HOST_CPU_VARIANTS="distro"
CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH:Q}

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/pocl

# The PLIST includes target-specific files so needs to be generated.
GENERATE_PLIST+=	find ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
			sed 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

.include "../../mk/bsd.prefs.mk"

# "LLVM could not recognize your CPU model automatically..."
.if !empty(MACHINE_ARCH:Maarch64*)
CMAKE_ARGS+=	-DLLC_HOST_CPU="cortex-a53"
.endif

pre-configure:
.if empty(PKGSRC_COMPILER:M*clang*)
# XXX: When using GCC, pkgsrc provides 'clang' wrappers that are actually gcc.
# XXX: This is copied from Firefox, which also needs this hack...
	${LN} -sf ${PREFIX}/bin/clang ${WRKDIR}/.cwrapper/bin/clang
	${LN} -sf ${PREFIX}/bin/clang++ ${WRKDIR}/.cwrapper/bin/clang++
	${LN} -sf ${PREFIX}/bin/clang-cpp ${WRKDIR}/.cwrapper/bin/clang-cpp
.endif

OWN_DIRS+=	${PKG_SYSCONFDIR}/OpenCL/vendors

CONF_FILES+=	${PREFIX}/share/examples/OpenCL/vendors/pocl.icd \
		${PKG_SYSCONFDIR}/OpenCL/vendors/pocl.icd

PKGCONFIG_OVERRIDE+=	pocl.pc.in.cmake

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../parallel/ocl-icd/buildlink3.mk"
.include "../../parallel/opencl-headers/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
