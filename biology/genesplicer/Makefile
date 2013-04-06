# $NetBSD: Makefile,v 1.13 2013/04/06 13:24:18 rodent Exp $
#

DISTNAME=		GeneSplicer
PKGNAME=		genesplicer-20030403
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/GeneSplicer/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		ftp://ftp.tigr.org/pub/software/GeneSplicer/
COMMENT=		Computational Method for Splice Site Prediction

USE_LANGUAGES=		c c++
USE_TOOLS+=		pax

EXDIR=			${PREFIX}/share/examples/genesplicer
EXAMPLES=		arabidopsis drosophila malaria pyoelii human rice \
			training_data_sets/Arabidopsis			  \
			training_data_sets/Human
MAKE_FILE=		makefile
BUILD_DIRS=		sources
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sources/genesplicer ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${EXDIR}
.for doc in readme fasta.example fasta.results
	${INSTALL_DATA} ${WRKSRC}/sources/${doc} ${DESTDIR}${EXDIR}
.endfor
	cd ${WRKSRC} && pax -rw ${EXAMPLES} ${DESTDIR}${EXDIR}

.include "../../mk/bsd.pkg.mk"
