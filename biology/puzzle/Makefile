# $NetBSD: Makefile,v 1.3 2001/07/08 13:36:33 jtb Exp $

DISTNAME=	tree-puzzle-5.0
PKGNAME=	puzzle-5.0
CATEGORIES=	biology
MASTER_SITES=	http://members.tripod.de/korbi/puzzle/ \
		ftp://ftp.ebi.ac.uk/pub/software/unix/puzzle/ \
		ftp://ftp.pasteur.fr/pub/GenSoft/unix/evolution/Puzzle/ \
		ftp://iubio.bio.indiana.edu/molbio/evolve/puzzle/ \
		http://iubio.bio.indiana.edu/soft/molbio/evolve/puzzle/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://www.tree-puzzle.de
COMMENT=	Maximum likelihood analysis of molecular sequence data

BUILD_DEPENDS=	mpich>=1.2.1:../../parallel/mpi-ch

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/puzzle
	cd ${WRKSRC}/doc; ${INSTALL_DATA} manual.html *.gif 		\
		${PREFIX}/share/doc/puzzle
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/puzzle
	cd ${WRKSRC}/data; ${INSTALL_DATA} atp6.a globin.a		\
		marswolf.n primates.b ${PREFIX}/share/examples/puzzle

.include "../../mk/bsd.pkg.mk"
