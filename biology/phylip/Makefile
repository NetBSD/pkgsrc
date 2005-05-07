# $NetBSD: Makefile,v 1.9 2005/05/07 20:43:39 kristerw Exp $

DISTNAME=	phylip-3.61
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/phylip/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://evolution.genetics.washington.edu/phylip.html
COMMENT=	Phylogeny Inference Package

RESTRICTED=		"No commercial distribution without a royalty agreement with the author"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_X11=	yes

do-install:
.for PROGRAM in clique consense contml contrast dnacomp dnadist		\
		dnainvar dnaml dnamlk dnamove dnapars dnapenny		\
		dolmove dollop dolpenny factor fitch gendist kitsch	\
		mix move neighbor pars penny proml promlk protdist	\
		protpars restdist restml retree seqboot treedist	\
		drawgram drawtree
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/fonts/phylip
.for FONT in font1 font2 font3 font4 font5 font6
	${INSTALL_DATA} ${WRKSRC}/${FONT} ${PREFIX}/share/fonts/phylip
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/phylip
.for HTML in clique.html consense.html contchar.html contml.html		\
		contrast.html discrete.html distance.html dnacomp.html	\
		dnadist.html dnainvar.html dnaml.html dnamlk.html	\
		dnamove.html dnapars.html dnapenny.html dollop.html	\
		dolmove.html dolpenny.html draw.html drawgram.html	\
		drawtree.html factor.html fitch.html gendist.html	\
		kitsch.html main.html mix.html move.html neighbor.html	\
		pars.html penny.html phylip.gif phylip.html proml.html	\
		promlk.html protdist.html protpars.html restdist.html	\
		restml.html retree.html seqboot.html sequence.html	\
		treedist.html
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${HTML} ${PREFIX}/share/doc/html/phylip
.endfor

.include "../../mk/bsd.pkg.mk"
