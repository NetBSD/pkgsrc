# $NetBSD: Makefile,v 1.8 2002/10/19 21:38:09 thorpej Exp $
#

DISTNAME=	simhv210-0b2
PKGNAME=	simh-2.10.0b2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
EXTRACT_SUFX=	.zip
EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		xq_beta4${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://simh.trailing-edge.com/
COMMENT=	Bob Supnik's historical computer simulator

WRKSRC=		${WRKDIR}

post-extract:
	${MKDIR} ${WRKSRC}/BIN
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	${MV} ${WRKSRC}/AltairZ80/altairZ80_defs.h \
	    ${WRKSRC}/AltairZ80/altairz80_defs.h
	${MV} ${WRKSRC}/SIMH/sim_ether.c ${WRKSRC}/sim_ether.c
	${MV} ${WRKSRC}/SIMH/sim_ether.h ${WRKSRC}/sim_ether.h
	${MV} ${WRKSRC}/SIMH/PDP11/pdp11_xq.c ${WRKSRC}/PDP11/pdp11_xq.c
	${MV} ${WRKSRC}/SIMH/PDP11/pdp11_xq.h ${WRKSRC}/PDP11/pdp11_xq.h
	${MV} ${WRKSRC}/SIMH/xq_README.txt ${WRKSRC}/xq_README.txt
	${RMDIR} ${WRKSRC}/SIMH/PDP11
	${RMDIR} ${WRKSRC}/SIMH

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
