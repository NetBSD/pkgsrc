# $NetBSD: Makefile,v 1.4 2001/09/09 20:36:16 agc Exp $

DISTNAME=	phylip
PKGNAME=	phylip-3.573c
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/phylip/ \
		ftp://ftp.bioss.sari.ac.uk/pub/phylogeny/phylip/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://evolution.genetics.washington.edu/phylip.html
COMMENT=	Phylogeny Inference Package

RESTRICTED=		"No commercial distribution without a royalty agreement with the author"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phylip
.for DOC in main.doc	\
		contchar.doc discrete.doc distance.doc draw.doc sequence.doc
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/phylip
.endfor
.for PROGRAM in clique consense contml contrast dnacomp dnadist		\
		dnainvar dnaml dnamlk dnamove dnapars dnapenny		\
		dolmove dollop dolpenny drawgram drawtree factor	\
		fitch gendist kitsch mix move neighbor penny		\
		protdist protpars restml retree seqboot
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PROGRAM}.doc ${PREFIX}/share/doc/phylip
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/misc/phylip
.for FONT in font1 font2 font3 font4 font5 font6
	${INSTALL_DATA} ${WRKSRC}/${FONT} ${PREFIX}/share/misc/phylip
.endfor

.include "../../mk/bsd.pkg.mk"
