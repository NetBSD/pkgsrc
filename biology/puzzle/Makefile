# $NetBSD: Makefile,v 1.5 2003/12/30 17:21:54 cjep Exp $

DISTNAME=	tree-puzzle-5.1
PKGNAME=	puzzle-5.1
CATEGORIES=	biology
MASTER_SITES=	http://members.tripod.de/korbi/puzzle/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/puzzle/ \
		ftp://ftp.pasteur.fr/pub/GenSoft/unix/evolution/Puzzle/ \
		ftp://iubio.bio.indiana.edu/molbio/evolve/puzzle/ \
		http://iubio.bio.indiana.edu/soft/molbio/evolve/puzzle/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://www.tree-puzzle.de/
COMMENT=	Maximum likelihood analysis of molecular sequence data

BUILD_DEPENDS=	mpich>=1.2.1:../../parallel/mpi-ch

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/puzzle
	cd ${WRKSRC}/doc && ${INSTALL_DATA} tree-puzzle.pdf	\
		${PREFIX}/share/doc/puzzle
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/puzzle
	cd ${WRKSRC}/doc && ${INSTALL_DATA} tree-puzzle.html	\
		*.gif ${PREFIX}/share/doc/html/puzzle
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/puzzle
	cd ${WRKSRC}/data && ${INSTALL_DATA} EF.* *.a *.n *.b	\
		${PREFIX}/share/examples/puzzle

.include "../../mk/bsd.pkg.mk"
