# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:40 jlam Exp $
#

DISTNAME=	fluctuate1.4.src.doc
PKGNAME=	fluctuate-1.4
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/lamarc/fluctuate/

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
	${INSTALL_PROGRAM} ${WRKSRC}/fluctuate ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXDIR}
	for f in ${DOCFILES}; do 				\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCDIR}/$$f; 	\
	done
	for f in ${EXFILES}; do 				\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EXDIR}/$$f; 	\
	done

.include "../../mk/bsd.pkg.mk"
