# $NetBSD: Makefile,v 1.7 2002/10/19 20:54:21 thorpej Exp $
#

DISTNAME=	simhv210-0b2
PKGNAME=	simh-2.10.0b2
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip
EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's historical computer simulator

WRKSRC=		${WRKDIR}

post-extract:
	${MKDIR} ${WRKSRC}/BIN
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	${MV} ${WRKSRC}/AltairZ80/altairZ80_defs.h \
	    ${WRKSRC}/AltairZ80/altairz80_defs.h

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
