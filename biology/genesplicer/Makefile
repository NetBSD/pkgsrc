# $NetBSD: Makefile,v 1.8 2006/02/26 13:41:17 schwarz Exp $
#

DISTNAME=		GeneSplicer
PKGNAME=		genesplicer-20030403
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/GeneSplicer/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		ftp://ftp.tigr.org/pub/software/GeneSplicer/
COMMENT=		Computational Method for Splice Site Prediction

USE_LANGUAGES=		c c++

EXDIR=			${PREFIX}/share/examples/genesplicer
EXAMPLES=		arabidopsis drosophila malaria pyoelii human rice \
			training_data_sets/Arabidopsis			  \
			training_data_sets/Human
MAKEFILE=		makefile
BUILD_DIRS=		sources
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sources/genesplicer ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EXDIR}
.for DOC in readme fasta.example fasta.results
	${INSTALL_DATA} ${WRKSRC}/sources/${DOC} ${EXDIR}
.endfor
	cd ${WRKSRC} && ${PAX} -rw ${EXAMPLES} ${EXDIR}/

.include "../../mk/bsd.pkg.mk"
