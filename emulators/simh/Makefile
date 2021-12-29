# $NetBSD: Makefile,v 1.61 2021/12/29 15:53:35 rhialto Exp $

DISTNAME=	simh-4.0.0
PKGNAME=	simh-4.0.0.20211212
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=simh/}
GITHUB_PROJECT=	simh
GITHUB_TAG=	40d46093853ed3d7e16331bfec713f4cfdea50fd

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supniks historical computer simulator
LICENSE=	mit

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

USE_TOOLS+=	gmake

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
# Doesn't seem to work with pkgsrc pcap, and dylib path is hardcoded.
PREFER.libpcap=		native
# Link error with the native version: _zlibVersion
PREFER.zlib=		pkgsrc
.endif

BUILDLINK_TRANSFORM+=	rm:-flto
BUILDLINK_TRANSFORM+=	rm:-fwhole-program

.if (${MACHINE_ARCH} == "arm")
BUILDLINK_TRANSFORM+=	rm:-O2
.endif

# Needed for PDP11/pdp11_dc.c on gcc 4.1.3
.if (${MACHINE_ARCH} == "vax")
CFLAGS+=	-fforce-addr
.endif

CFLAGS.SunOS+=	-DBSD_COMP
LDFLAGS.SunOS+=	-lm

LDFLAGS.Linux+=	-lm -pthread -lrt

INSTALLATION_DIRS=	bin share/simh share/simh/TX-0 share/doc/simh

MAKE_FILE=		makefile
INCLUDES=		${PREFIX:Q}/include:\
			${BUILDLINK_PREFIX.SDL2:Q}/include/SDL2:\
			${BUILDLINK_PREFIX.libpcap:Q}/include/pcap:\
			${BUILDLINK_PREFIX.pcre:Q}/include/pcre:\
			${BUILDLINK_PREFIX.png:Q}/include:\
			/usr/include
LIBRARIES=		${PREFIX:Q}/lib:\
			${BUILDLINK_PREFIX.SDL2:Q}/lib${LIBABISUFFIX}:\
			${BUILDLINK_PREFIX.libpcap:Q}/lib${LIBABISUFFIX}:\
			${BUILDLINK_PREFIX.pcre:Q}/lib${LIBABISUFFIX}:\
			${BUILDLINK_PREFIX.png:Q}/lib${LIBABISUFFIX}:\
			/usr/lib${LIBABISUFFIX}
MAKE_ENV+=		INCLUDES=${INCLUDES:Q}
MAKE_ENV+=		LIBRARIES=${LIBRARIES:Q}
MAKE_ENV+=		GCC=${CC:Q}
MAKE_ENV+=		OS_LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=		FONTPATH=${PREFIX}/share/fonts/X11/TTF

BUILD_MAKE_FLAGS=	TESTS=0


post-extract:
	${MKDIR} ${WRKSRC}/BIN

do-install:
	(cd ${WRKSRC}/BIN && for BIN in *; do				\
		if [ -f $$BIN ] ; then					\
		${INSTALL_PROGRAM} $$BIN ${DESTDIR}${PREFIX}/bin/simh-$$BIN; \
		fi ;							\
	done)

	${INSTALL_DATA} ${WRKSRC}/TX-0/*.bin ${DESTDIR}${PREFIX}/share/simh/TX-0
	(cd ${WRKSRC} && for TXT in *.txt */*.txt; do			\
		${INSTALL_DATA} "$$TXT" ${DESTDIR}${PREFIX}/share/doc/simh;		\
	done)

# Note: tests require shm (/var/shm is a tmpfs) for the uc15.
# They are part of the build and can't be run separately.
do-test:
	cd ${WRKSRC} && ${TEST_MAKE_CMD} clean
	cd ${WRKSRC} && ${TEST_MAKE_CMD} all

.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
