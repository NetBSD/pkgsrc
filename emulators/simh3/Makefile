# $NetBSD: Makefile,v 1.2 2022/08/11 05:08:21 gutteridge Exp $

DISTNAME=	simhv312-2
PKGNAME=	simh3-3.12.2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's simulator for historic computer systems
LICENSE=	modified-bsd # (essentially)

WRKSRC=		${WRKDIR}/sim
USE_TOOLS+=	gmake

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9

BUILDLINK_TRANSFORM+=	rm:-flto
BUILDLINK_TRANSFORM+=	rm:-fwhole-program

INSTALLATION_DIRS=	bin share/simh3 share/doc/simh3

MAKE_FILE=	makefile
INCLUDES=	${PREFIX:Q}/include:\
		${BUILDLINK_PREFIX.SDL2:Q}/include/SDL2:\
		${BUILDLINK_PREFIX.libpcap:Q}/include/pcap:\
		${BUILDLINK_PREFIX.pcre:Q}/include/pcre:\
		${BUILDLINK_PREFIX.png:Q}/include:\
		/usr/include
LIBRARIES=	${PREFIX:Q}/lib:\
		${BUILDLINK_PREFIX.SDL2:Q}/lib${LIBABISUFFIX}:\
		${BUILDLINK_PREFIX.libpcap:Q}/lib${LIBABISUFFIX}:\
		${BUILDLINK_PREFIX.pcre:Q}/lib${LIBABISUFFIX}:\
		${BUILDLINK_PREFIX.png:Q}/lib${LIBABISUFFIX}:\
		/usr/lib${LIBABISUFFIX}
MAKE_ENV+=	INCLUDES=${INCLUDES:Q}
MAKE_ENV+=	LIBRARIES=${LIBRARIES:Q}
MAKE_ENV+=	GCC=${CC:Q}
MAKE_ENV+=	OS_LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=	FONTPATH=${PREFIX}/share/fonts/X11/TTF

do-install:
	(cd ${WRKSRC}/BIN && for BIN in *; do                           \
		if [ -f $$BIN ] ; then                                  \
		${INSTALL_PROGRAM} $$BIN ${DESTDIR}${PREFIX}/bin/simh3-$$BIN; \
		fi ;                                                    \
	done)
	cd ${WRKSRC} && ${INSTALL_DATA} VAX/ka655x.bin ${DESTDIR}${PREFIX}/share/simh3
	(cd ${WRKSRC} && for TXT in *.txt */*.txt; do                   \
		${INSTALL_DATA} "$$TXT" ${DESTDIR}${PREFIX}/share/doc/simh3; \
	done)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
