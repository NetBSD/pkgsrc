# $NetBSD: Makefile,v 1.6 2002/08/20 23:58:14 soren Exp $
#

DISTNAME=	simhv29-11
PKGNAME=	simh-2.9.11
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip
EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's historical computer simulator

WRKSRC=		${WRKDIR}

pre-build:
	${MKDIR} ${WRKSRC}/BIN
	-${MV} ${WRKSRC}/AltairZ80/altairz80_defs.h \
		${WRKSRC}/AltairZ80/altairZ80_defs.h

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
