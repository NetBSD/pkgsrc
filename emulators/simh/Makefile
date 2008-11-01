# $NetBSD: Makefile,v 1.27 2008/11/01 05:15:42 obache Exp $
#

DISTNAME=	simhv38-0
PKGNAME=	simh-3.8.0
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's historical computer simulator

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6

EXTRACT_OPTS_ZIP=	-aoq
WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "arm")
BUILDLINK_TRANSFORM+=	rm:-O2
.endif

INSTALLATION_DIRS=	bin share/simh share/doc/simh

MAKE_FILE=		makefile

post-extract:
	${MKDIR} ${WRKSRC}/BIN

do-install:
	(cd ${WRKSRC}/BIN && for BIN in *; do				\
		${INSTALL_PROGRAM} $$BIN ${DESTDIR}${PREFIX}/bin/simh-$$BIN;	\
	done)
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/simh
	${INSTALL_DATA} ${WRKSRC}/VAX/ka655x.bin ${DESTDIR}${PREFIX}/share/simh
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/simh
	(cd ${WRKSRC} && for TXT in *.txt */*.txt; do			\
		${INSTALL_DATA} $$TXT ${DESTDIR}${PREFIX}/share/doc/simh;		\
	done)

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
