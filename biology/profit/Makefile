# $NetBSD: Makefile,v 1.2 2004/01/20 12:08:40 agc Exp $
#

DISTNAME=		profit
PKGNAME=		profit-2.2
CATEGORIES=		biology
MASTER_SITES=		http://www.rubic.rdg.ac.uk/~andrew/bioinf.org/software/profit/235216/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.rubic.rdg.ac.uk/~andrew/bioinf.org/software/profit/index.html
COMMENT=		Performs least squares fits of two protein structures

ALL_TARGET=		${DISTNAME}
USE_BUILDLINK2=		YES
WRKSRC=			${WRKDIR}/ProFitV2.2/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/profit ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/profit
.for sufx in dvi ps tex
	${INSTALL_DATA} ${WRKSRC}/../doc/ProFit.${sufx} 		\
		${PREFIX}/share/doc/profit
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/profit
	cd ${WRKSRC}/../doc/ProFit/ && 					\
		${PAX} -rw . ${PREFIX}/share/doc/html/profit/

.include "../../mk/bsd.pkg.mk"
