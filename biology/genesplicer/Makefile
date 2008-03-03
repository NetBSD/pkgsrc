# $NetBSD: Makefile,v 1.10 2008/03/03 01:10:05 jlam Exp $
#

DISTNAME=		GeneSplicer
PKGNAME=		genesplicer-20030403
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/GeneSplicer/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		ftp://ftp.tigr.org/pub/software/GeneSplicer/
COMMENT=		Computational Method for Splice Site Prediction

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

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
.for DOC in readme fasta.example fasta.results
	${INSTALL_DATA} ${WRKSRC}/sources/${DOC} ${DESTDIR}${EXDIR}
.endfor
	cd ${WRKSRC} && ${PAX} -rw ${EXAMPLES} ${DESTDIR}${EXDIR}

.include "../../mk/bsd.pkg.mk"
