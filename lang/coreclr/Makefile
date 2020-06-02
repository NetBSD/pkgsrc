# $NetBSD: Makefile,v 1.13 2020/06/02 08:22:45 adam Exp $

DISTNAME=	coreclr-1.0.0
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dotnet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

EXTRACT_USING=	bsdtar

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://dotnet.github.io/
COMMENT=	The .NET Core runtime and the base library
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash pax
# We need to set CMake this way to get defined CMAKE_ARGS
USE_CMAKE=	yes
CMAKE_ARGS+=	-DCORECLR_SET_RPATH:BOOL=OFF

REPLACE_BASH+=	build.sh
REPLACE_BASH+=	src/pal/tools/gen-buildsys-clang.sh
REPLACE_BASH+=	src/pal/tests/palsuite/runpaltests.sh

CORECLR_PREFIX=	${PREFIX}/CoreCLR

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64"
CORECLR_ARCH=	x64
.endif

CORECLR_OBJDIR=		${WRKSRC}/bin/obj/${OPSYS}.${CORECLR_ARCH}.Debug
CORECLR_PRODUCTDIR=	${WRKSRC}/bin/Product/${OPSYS}.${CORECLR_ARCH}.Debug

# Handle subprefix
LDFLAGS+=	${COMPILER_RPATH_FLAG}${CORECLR_PREFIX:Q}
LDFLAGS+=	${COMPILER_RPATH_FLAG}${CORECLR_PREFIX:Q}/Loader/NativeLibs
LDFLAGS+=	${COMPILER_RPATH_FLAG}${CORECLR_PREFIX:Q}/bin

BUILDLINK_PASSTHRU_DIRS+=	${CORECLR_PREFIX:Q}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${CORECLR_PREFIX:Q}

# DOTNET targets only LLVM
PKGSRC_COMPILER=	clang
PKG_CC=			clang
PKG_CXX=		clang++
_WRAP_EXTRA_ARGS.CXX+=	-Wno-unused-function -Wno-self-assign
CWRAPPERS_APPEND.cxx+=	-Wno-unused-function -Wno-self-assign


TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/bin/obj/${OPSYS}.x64.Debug/src/pal/tests/palsuite/exception_handling/pal_sxs/test1

do-configure:
	${RUN} ${ECHO} Skip configure and call CMake via build.sh

do-build:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} PYTHON=${PYTHONBIN:Q} \
		./build.sh skipmscorlib cmakeargs ${CMAKE_ARGS:Q}

# Currently there is no unix-like install target.
# Put all produced files under subprefix.
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${CORECLR_PREFIX:Q}
	cd ${CORECLR_PRODUCTDIR} && ${PAX} -rw . ${DESTDIR}${CORECLR_PREFIX:Q}

do-test:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} src/pal/tests/palsuite/runpaltests.sh \
		${CORECLR_OBJDIR} ${WRKSRC}/paltestout

.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../devel/lldb/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
