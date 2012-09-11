# $NetBSD: Makefile,v 1.9 2012/09/11 20:32:12 asau Exp $
#

DISTNAME=	fluctuate1.4.src.doc
PKGNAME=	fluctuate-1.4
CATEGORIES=	biology
MASTER_SITES=	http://evolution.gs.washington.edu/lamarc/fluctuate/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://evolution.genetics.washington.edu/lamarc/fluctuate.html
COMMENT=	Estimation of population growth rate

WRKSRC=		${WRKDIR}/fluctuate1.4
BUILD_TARGET=	fluctuate

DOCDIR=		${PREFIX}/share/doc/fluctuate
EXDIR=		${PREFIX}/share/examples/fluctuate
DOCFILES=	fluctuate.doc errors.doc
EXFILES=	bestree infile outfile

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fluctuate ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EXDIR}
	for f in ${DOCFILES}; do 					\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${DOCDIR}/$$f; 	\
	done
	for f in ${EXFILES}; do 					\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${EXDIR}/$$f; 	\
	done

.include "../../mk/bsd.pkg.mk"
