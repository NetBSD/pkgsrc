# $NetBSD: Makefile,v 1.219 2024/06/04 08:33:04 adam Exp $

.include "Makefile.common"

COMMENT=	Cross platform make

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap

BUILD_TARGET=		default_target

CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--bootstrap-system-libuv
CONFIGURE_ARGS+=	--bootstrap-system-librhash
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
CONFIGURE_ARGS+=	--docdir=/share/doc/cmake-${CMAKE_API}
CONFIGURE_ARGS+=	--parallel=${MAKE_JOBS:U1}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--system-libs
# Debugger is not available for all platforms
CONFIGURE_ARGS+=	--no-debugger
# cppdap and jsoncpp require cmake to build, so use the one provided with cmake
CONFIGURE_ARGS+=	--no-system-cppdap
CONFIGURE_ARGS+=	--no-system-jsoncpp

LDFLAGS.Darwin+=	-framework CoreServices # for LSOpenCFURLRef()
LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

.if ${INSTALL_UNSTRIPPED:Uno:tl} != yes
INSTALL_TARGET=		install/strip
.endif

# Enforce arm64 to support building inside x86_64 chroots.
.if ${MACHINE_PLATFORM:MDarwin-*-aarch64}
CONFIGURE_ENV+=		CMAKE_OSX_ARCHITECTURES=arm64
.endif

PLIST_SUBST+=		CMAKE_API=${CMAKE_API}

REPLACE_SH=		Modules/Compiler/XL-Fortran/cpp

# for Source/cmDependsJavaParser.cxx
UNLIMIT_RESOURCES=	datasize

# as of 2.4.6, x11 and fortran tests fail in pkgsrc
TEST_TARGET=		test

SUBST_CLASSES+=		cmake
SUBST_STAGE.cmake=	pre-configure
SUBST_MESSAGE.cmake=	Fixing LOCALBASE and X11 paths.
SUBST_FILES.cmake+=	Modules/FindX11.cmake
SUBST_FILES.cmake+=	Modules/Platform/UnixPaths.cmake
SUBST_VARS.cmake=	LOCALBASE X11BASE

# Use custom shell for Makefiles. For most platforms this is a no-op.
# On Darwin, system /bin/sh is restricted, so DYLD_LIBRARY_PATH can't be used.
# This is needed for packages that execute binaries linked with not-yet
# installed shared libraries, like qt6-qtbase.
SUBST_CLASSES+=		shell
SUBST_STAGE.shell=	pre-configure
SUBST_MESSAGE.shell=	Set custom SHELL in generated Makefiles.
SUBST_FILES.shell+=	Source/cmLocalUnixMakefileGenerator3.cxx
SUBST_SED.shell=	-e 's,/bin/sh,${SH},g'

pre-configure:
	${CP} ${FILESDIR}/Source_Checks_cm_cxx_cbegin.cxx ${WRKSRC}/Source/Checks/cm_cxx_cbegin.cxx
	${CP} ${FILESDIR}/Source_Checks_cm_cxx_cend.cxx ${WRKSRC}/Source/Checks/cm_cxx_cend.cxx
	${CP} ${FILESDIR}/Source_Checks_cm_cxx_size_t.cxx ${WRKSRC}/Source/Checks/cm_cxx_size_t.cxx
	${FIND} ${WRKSRC}/Modules -type f -a -name "*.orig" -print | ${XARGS} ${RM}
	${LN} -f ${WRKSRC}/Modules/Platform/OpenBSD.cmake ${WRKSRC}/Modules/Platform/MirBSD.cmake
.for lang in C CXX Fortran
	${LN} -f ${WRKSRC}/Modules/Platform/SunOS-GNU-${lang}.cmake \
	    ${WRKSRC}/Modules/Platform/SunOS-Clang-${lang}.cmake
.endfor

USE_CURSES=		wsyncup

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.3.3
BUILDLINK_API_DEPENDS.rhash+=	rhash>=1.4.2nb1
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/curses.buildlink3.mk"

.if !exists(${BUILDLINK_INCDIRS.curses}/form.h) && \
     exists(${BUILDLINK_INCDIRS.curses}/ncurses/form.h)
CFLAGS+=	-I${BUILDLINK_INCDIRS.curses}/ncurses
CXXFLAGS+=	-I${BUILDLINK_INCDIRS.curses}/ncurses
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
