# $NetBSD: Makefile,v 1.15 2003/07/17 21:35:44 grant Exp $
#

DISTNAME=	simhv210-4
PKGNAME=	simh-2.10.4
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's historical computer simulator

EXTRACT_CMD=	unzip -aoq ${DOWNLOADED_DISTFILE}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "arm")
.if (${CFLAGS:M-O2} == "-O2")
CFLAGS:=	${CFLAGS:S/-O2//}
.endif
.endif

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

.include "../../mk/bsd.pkg.mk"
