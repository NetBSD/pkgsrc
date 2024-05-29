# $NetBSD: Makefile,v 1.195 2024/05/29 16:32:26 adam Exp $

DISTNAME=	mame-0.265
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=mamedev/}
GITHUB_TAG=	${DISTNAME:S/-//S/.//}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://www.mamedev.org/
COMMENT=	Multiple Arcade Machine Emulator
LICENSE=	modified-bsd AND gnu-gpl-v2

DOCDIR=			share/doc/mame
SHAREDIR=		share/mame
INSTALLATION_DIRS=	bin ${DOCDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man6
INSTALLATION_DIRS+=	${SHAREDIR}/artwork/bgfx/border_blur
INSTALLATION_DIRS+=	${SHAREDIR}/artwork/bgfx/chains/crt-geom ${SHAREDIR}/hash

DEPENDS+=		liberation-ttf-[0-9]*:../../fonts/liberation-ttf

USE_LANGUAGES=		c99 c++
USE_CXX_FEATURES+=	c++17
USE_TOOLS+=		gmake pkg-config
UNLIMIT_RESOURCES+=	cputime datasize memorysize virtualsize
MAKE_FILE=		makefile

# complains with earlier versions:
# "GCC version 10.3 or later needed"
GCC_REQD+=		10

# Need to use gnu++ instead of c++ to get __builtin_alloca() (!)
FORCE_CXX_STD=		gnu++17

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS+=		PRECOMPILE=0
# TODO: set differently when debugging?
MAKE_FLAGS+=		OPTIMIZE=2
MAKE_FLAGS+=		NO_USE_PORTAUDIO=1
MAKE_FLAGS+=		NO_USE_PULSEAUDIO=1

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
# \todo Arch detection for aarch64 fails, investigate why
MAKE_FLAGS+=		NOASM=1
MAKE_FLAGS+=		FORCE_DRC_C_BACKEND=1
BUILDLINK_TRANSFORM+=	rm:-m32
BUILDLINK_TRANSFORM+=	rm:-m64
.endif

# "error: inlining failed in call to always_inline
# '__m128i _mm_shuffle_epi8(__m128i, __m128i)': target specific option mismatch"
.if ${MACHINE_ARCH} == "x86_64"
CFLAGS+=	-mssse3
.endif

# -Werror is problematic
MAKE_ENV+=	NOWERROR=1
# on Darwin, avoid SDL2.framework
MAKE_ENV+=	USE_LIBSDL=1

# for c++ to get LLONG_MAX for luaconf.h
CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE

# use pkgsrc libraries
# boost-header's asio.hpp is not compatible as of mame-0.251/boost 1.81.0
#MAKE_ENV+=	USE_SYSTEM_LIB_ASIO=1
MAKE_ENV+=	USE_SYSTEM_LIB_EXPAT=1
MAKE_ENV+=	USE_SYSTEM_LIB_ZLIB=1
MAKE_ENV+=	USE_SYSTEM_LIB_JPEG=1
MAKE_ENV+=	USE_SYSTEM_LIB_FLAC=1
# use audio from SDL
#MAKE_ENV+=	USE_SYSTEM_LIB_PORTAUDIO=1
# no portmidi package exists yet
#MAKE_ENV+=	USE_SYSTEM_LIB_PORTMIDI=1
MAKE_ENV+=	USE_SYSTEM_LIB_SQLITE3=1
MAKE_ENV+=	USE_SYSTEM_LIB_UTF8PROC=1
MAKE_ENV+=	USE_SYSTEM_LIB_GLM=1
MAKE_ENV+=	USE_SYSTEM_LIB_RAPIDJSON=1
MAKE_ENV+=	USE_SYSTEM_LIB_PUGIXML=1
# find proper python binary
MAKE_ENV+=	PYTHON_EXECUTABLE=${PYTHONBIN}
# don't depend on qt5
MAKE_ENV+=	USE_QTDEBUG=0
# avoid midi for now
#MAKE_ENV+=	NO_USE_MIDI=1
# build tools
MAKE_ENV+=	TOOLS=1

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
MAKE_ENV+=	BIGENDIAN=1
.endif

PYTHON_FOR_BUILD_ONLY=		yes

post-extract:
	# will be chosen in preference to /usr/include/signal.h, but does not provide kill()
	${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/signal.h
	# will be chosen in preference to /usr/include/dirent.h, but does not provide opendir() et al.
	${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/dirent.h
	${MV} ${WRKSRC}/3rdparty/genie/build/gmake.freebsd ${WRKSRC}/3rdparty/genie/build/gmake.bsd

pre-build:
	# problems with mame-specific png.h
	${RM} -f ${WRKDIR}/.buildlink/include/png*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mame ${DESTDIR}${PREFIX}/bin/mame
	set -e; \
	for prg in castool chdman floptool imgtool jedutil ldresample ldverify \
		nltool nlwav pngcmp regrep romcmp split srcclean unidasm; do \
		${INSTALL_PROGRAM} ${WRKSRC}/"$$prg" ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/docs/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/docs/man/*.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${WRKSRC}/artwork/LICENSE ${DESTDIR}${PREFIX}/${SHAREDIR}/artwork
	${INSTALL_DATA} ${WRKSRC}/artwork/*.* ${DESTDIR}${PREFIX}/${SHAREDIR}/artwork
	${INSTALL_DATA} ${WRKSRC}/artwork/bgfx/border_blur/* ${DESTDIR}${PREFIX}/${SHAREDIR}/artwork/bgfx/border_blur
	${INSTALL_DATA} ${WRKSRC}/artwork/bgfx/chains/*.* ${DESTDIR}${PREFIX}/${SHAREDIR}/artwork/bgfx/chains
	${INSTALL_DATA} ${WRKSRC}/artwork/bgfx/chains/crt-geom/* ${DESTDIR}${PREFIX}/${SHAREDIR}/artwork/bgfx/chains/crt-geom/
	${INSTALL_DATA} ${WRKSRC}/docs/*.md ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/hash/* ${DESTDIR}${PREFIX}/${SHAREDIR}/hash

.include "../../audio/flac/buildlink3.mk"
.include "../../converters/utf8proc/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/pyversion.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
