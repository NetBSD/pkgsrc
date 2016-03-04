# $NetBSD: Makefile,v 1.53 2016/03/04 12:47:13 wiz Exp $

DISTNAME=	mame-0.171
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=mamedev/}
GITHUB_TAG=	${DISTNAME:S/-//S/.//}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.mamedev.org/
COMMENT=	Multiple Arcade Machine Emulator
LICENSE=	mame-license

DOCDIR=			share/doc/mame
SHAREDIR=		share/mame
INSTALLATION_DIRS=	bin ${DOCDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man6
INSTALLATION_DIRS+=	${SHAREDIR}/artwork ${SHAREDIR}/hash

RESTRICTED=		selling is not allowed
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DEPENDS+=		liberation-ttf-[0-9]*:../../fonts/liberation-ttf

USE_LANGUAGES=		c99 c++
# 4.9 is enough, but doesn't build with SSP support on NetBSD
GCC_REQD=		5.3
USE_TOOLS+=		bsdtar gmake pkg-config
UNLIMIT_RESOURCES+=	datasize
MAKE_FILE=		makefile
EXTRACT_USING=		bsdtar
# 0.141 has too many conversion warnings
MAKE_ENV=		NOWERROR=1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# also needs kvm and I didn't find the right place to add it in the build system
MAKE_ENV+=	LDOPTS="-Wl,-R${BUILDLINK_PREFIX.flac}/lib -L${BUILDLINK_PREFIX.flac}/lib -lpthread -lkvm"
.else
# mongoose needs libpthread but somehow doesn't link against it
MAKE_ENV+=	LDOPTS="-Wl,-R${BUILDLINK_PREFIX.flac}/lib -L${BUILDLINK_PREFIX.flac}/lib -lpthread"
.endif

# use pkgsrc packages for expat, zlib, jpeg, flac, lua, sqlite3
MAKE_ENV+=	USE_SYSTEM_LIB_EXPAT=1
MAKE_ENV+=	USE_SYSTEM_LIB_ZLIB=1
MAKE_ENV+=	USE_SYSTEM_LIB_JPEG=1
MAKE_ENV+=	USE_SYSTEM_LIB_FLAC=1
MAKE_ENV+=	USE_SYSTEM_LIB_LUA=1
MAKE_ENV+=	USE_SYSTEM_LIB_SQLITE3=1
# no portmidi package exists yet
#MAKE_ENV+=	USE_SYSTEM_LIB_PORTMIDI=1
# find proper python binary
MAKE_ENV+=	PYTHON_EXECUTABLE=${PYTHONBIN}
# don't depend on qt4
MAKE_ENV+=	USE_QTDEBUG=0
# avoid midi for now
#MAKE_ENV+=	NO_USE_MIDI=1
# build tools
MAKE_ENV+=	TOOLS=1

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=cast-align \
			-Wno-error=constant-logical-operand \
			-Wno-error=sometimes-uninitialized \
			-Wno-error=shift-count-overflow \
			-Wno-error=unused-private-field \
			-Wno-error=tautological-constant-out-of-range-compare \
			-Wno-error=tautological-compare \
			-Wno-error=self-assign-field \
			-Wno-error=unused-const-variable \
			-Wno-error=unused-function
CWRAPPERS_APPEND.cc+=	-Wno-error=cast-align \
			-Wno-error=constant-logical-operand \
			-Wno-error=sometimes-uninitialized \
			-Wno-error=shift-count-overflow \
			-Wno-error=unused-private-field \
			-Wno-error=tautological-constant-out-of-range-compare \
			-Wno-error=tautological-compare \
			-Wno-error=self-assign-field \
			-Wno-error=unused-const-variable \
			-Wno-error=unused-function
MAKE_ENV+=		OPTIMIZE=2
.endif

.  include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN:Mbig}
MAKE_ENV+=	BIGENDIAN=1
.endif

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.151

post-extract:
	# will be chosen in preference to /usr/include/signal.h, but does not provide kill()
	${RM} ${WRKSRC}/3rdparty/bx/include/compat/freebsd/signal.h

pre-build:
	# problems with mame-specific png.h
	${RM} -f ${WRKDIR}/.buildlink/include/png*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mame64 ${DESTDIR}${PREFIX}/bin/mame
	set -e; \
	for prg in castool chdman floptool imgtool jedutil ldresample ldverify \
		nltool pngcmp regrep romcmp split src2html srcclean testkeys unidasm; \
	do \
		${INSTALL_PROGRAM} ${WRKSRC}/"$$prg" ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/src/osd/sdl/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/src/osd/sdl/man/*.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA} ${WRKSRC}/artwork/* ${DESTDIR}${PREFIX}/${SHAREDIR}/artwork
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/hash/* ${DESTDIR}${PREFIX}/${SHAREDIR}/hash

.include "../../lang/python/application.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
