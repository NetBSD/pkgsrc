# $NetBSD: Makefile,v 1.9 2012/09/11 20:32:11 asau Exp $
#

DISTNAME=	coalesce1.5b
PKGNAME=	coalesce-1.5.0.2
CATEGORIES=	biology
MASTER_SITES=	http://evolution.genetics.washington.edu/lamarc/coalesce/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://evolution.genetics.washington.edu/lamarc/coalesce.html
COMMENT=	Estimates effective population size and mutation rate

WRKSRC=		${WRKDIR}/coalesce1.5beta
BUILD_TARGET=	coalesce

DOCDIR=		${PREFIX}/share/doc/coalesce
EXDIR=		${PREFIX}/share/examples/coalesce
DOCFILES=	coalesce.doc errors.doc readme
EXFILES=	bestree infile intree outfile parmfile seedfile

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EXDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/coalesce ${DESTDIR}${PREFIX}/bin
	for f in ${DOCFILES}; do 					\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${DOCDIR}/$$f; 	\
	done
	for f in ${EXFILES}; do 					\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${EXDIR}/$$f; 	\
	done

.include "../../mk/bsd.pkg.mk"
