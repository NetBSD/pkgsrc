# $NetBSD: Makefile,v 1.4 2004/08/14 20:52:09 ben Exp $
#

DISTNAME=		profit
PKGNAME=		profit-2.2
CATEGORIES=		biology
MASTER_SITES=		http://acrmwww.biochem.ucl.ac.uk/software/profit/235216/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://acrmwww.biochem.ucl.ac.uk/programs/profit/index.html
COMMENT=		Performs least squares fits of two protein structures

ALL_TARGET=		${DISTNAME}
USE_BUILDLINK3=		YES
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
