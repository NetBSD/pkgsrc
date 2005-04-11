# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:00 tv Exp $
#

DISTNAME=	coalesce1.5b
PKGNAME=	coalesce-1.5.0.2
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/lamarc/coalesce/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://evolution.genetics.washington.edu/lamarc/coalesce.html
COMMENT=	Estimates effective population size and mutation rate

WRKSRC=		${WRKDIR}/coalesce1.5beta
BUILD_TARGET=	coalesce

DOCDIR=		${PREFIX}/share/doc/coalesce
EXDIR=		${PREFIX}/share/examples/coalesce
DOCFILES=	coalesce.doc errors.doc readme
EXFILES=	bestree infile intree outfile parmfile seedfile

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/coalesce ${PREFIX}/bin/
	for f in ${DOCFILES}; do 				\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCDIR}/$$f; 	\
	done
	for f in ${EXFILES}; do 				\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EXDIR}/$$f; 	\
	done

.include "../../mk/bsd.pkg.mk"
