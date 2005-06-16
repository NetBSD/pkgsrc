# $NetBSD: Makefile,v 1.21 2005/06/16 06:57:51 jlam Exp $
#

DISTNAME=	simhv33-0
PKGNAME=	simh-3.3.0
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's historical computer simulator

BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.6

EXTRACT_CMD=	unzip -aoq ${DOWNLOADED_DISTFILE}
WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "arm")
.if (${CFLAGS:M-O2} == "-O2")
CFLAGS:=	${CFLAGS:S/-O2//}
.endif
.endif

INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKSRC}/BIN
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC}/BIN && for BIN in *; do				\
		${INSTALL_PROGRAM} $$BIN ${PREFIX}/bin/simh-$$BIN;	\
	done)
	${INSTALL_DATA_DIR} ${PREFIX}/share/simh
	${INSTALL_DATA} ${WRKSRC}/VAX/ka655.bin ${PREFIX}/share/simh
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/simh
	(cd ${WRKSRC} && for TXT in *.txt */*.txt; do			\
		${INSTALL_DATA} $$TXT ${PREFIX}/share/doc/simh;		\
	done)

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
