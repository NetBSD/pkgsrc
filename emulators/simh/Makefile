# $NetBSD: Makefile,v 1.41 2013/03/26 13:43:19 martin Exp $

DISTNAME=	simhv39-0
PKGNAME=	simh-3.9.0
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supniks historical computer simulator

USE_TOOLS+=	gmake

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.9

WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "arm")
BUILDLINK_TRANSFORM+=	rm:-O2
.endif

# Needed for PDP11/pdp11_dc.c on gcc 4.1.3
.if (${MACHINE_ARCH} == "vax")
CFLAGS+=	-fforce-addr
.endif

INSTALLATION_DIRS=	bin share/simh share/doc/simh

MAKE_FILE=		makefile
MAKE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}
MAKE_ENV+=		GCC=${CC:Q}
MAKE_ENV+=		OS_LDFLAGS=${LDFLAGS:Q} CFLAGS_O=${CFLAGS:Q}

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
		${INSTALL_DATA} $$TXT ${DESTDIR}${PREFIX}/share/doc/simh;		\
	done)

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
