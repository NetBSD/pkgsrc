# $NetBSD: Makefile,v 1.1.1.1 1999/07/28 19:55:17 rh Exp $

DISTNAME=	puzzle-402
PKGNAME=	puzzle-4.0.2
WRKSRC=		${WRKDIR}/${PKGNAME}/src
CATEGORIES=	biology
MASTER_SITES=	http://members.tripod.de/korbi/puzzle/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/puzzle/ \
		ftp://ftp.pasteur.fr/pub/GenSoft/unix/evolution/Puzzle/ \
		ftp://iubio.bio.indiana.edu/molbio/evolve/puzzle/ \
		http://iubio.bio.indiana.edu/soft/molbio/evolve/puzzle/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://members.tripod.de/korbi/puzzle/

MAKEFILE=	makefile
ALL_TARGET=	puzzle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/puzzle ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/puzzle
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME}/doc/manual.html ${PREFIX}/share/doc/puzzle

.include "../../mk/bsd.pkg.mk"
