# $NetBSD: Makefile,v 1.54 2020/03/27 15:25:36 ryoon Exp $

DISTNAME=	simh-4.0.0
PKGNAME=	simh-4.0.0.20180919
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=simh/}
GITHUB_PROJECT=	simh
GITHUB_TAG=	0fe4bf3281a4d1f9fd10bba07cf0f7e40da92fc3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supniks historical computer simulator
LICENSE=	mit

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

USE_TOOLS+=	gmake

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9

.include "../../mk/bsd.prefs.mk"

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

INSTALLATION_DIRS=	bin share/simh share/doc/simh

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
MAKE_ENV+=		OS_LDFLAGS=${LDFLAGS:Q} CFLAGS_O=${CFLAGS:Q}
MAKE_ENV+=		FONTPATH=/usr/pkg/share/fonts/X11/TTF

BUILD_TARGET=		all besm6

post-extract:
	${MKDIR} ${WRKSRC}/BIN

do-install:
	(cd ${WRKSRC}/BIN && for BIN in *; do				\
		if [ -f $$BIN ] ; then					\
		${INSTALL_PROGRAM} $$BIN ${DESTDIR}${PREFIX}/bin/simh-$$BIN; \
		fi ;							\
	done)

	${INSTALL_DATA} ${WRKSRC}/VAX/ka655x.bin ${DESTDIR}${PREFIX}/share/simh
	${INSTALL_DATA} ${WRKSRC}/VAX/vmb.exe ${DESTDIR}${PREFIX}/share/simh
	(cd ${WRKSRC} && for TXT in *.txt */*.txt; do			\
		${INSTALL_DATA} "$$TXT" ${DESTDIR}${PREFIX}/share/doc/simh;		\
	done)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
