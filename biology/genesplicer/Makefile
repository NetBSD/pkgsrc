# $NetBSD: Makefile,v 1.1.1.1 2003/09/30 01:57:08 jschauma Exp $
#

DISTNAME=		GeneSplicer
PKGNAME=		genesplicer-20030403
WRKSRC=			${WRKDIR}/GeneSplicer/sources
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/GeneSplicer/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		ftp://ftp.tigr.org/pub/software/GeneSplicer/
COMMENT=		Computational Method for Splice Site Prediction

EXDIR=			${PREFIX}/share/examples/genesplicer
EXAMPLES=		arabidopsis drosophila malaria pyoelii human rice \
			training_data_sets/Arabidopsis			  \
			training_data_sets/Human
MAKEFILE=		makefile
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/genesplicer ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${EXDIR}
.for DOC in readme fasta.example fasta.results
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${EXDIR}
.endfor
	cd ${WRKSRC}/../ && ${PAX} -rw ${EXAMPLES} ${EXDIR}/

.include "../../mk/bsd.pkg.mk"

