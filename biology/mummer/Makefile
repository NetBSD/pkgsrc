# $NetBSD: Makefile,v 1.11 2006/01/29 19:31:43 schwarz Exp $
#

DISTNAME=		MUMmer3.18
PKGNAME=		mummer-3.18
CATEGORIES=		biology
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mummer/}

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://mummer.sourceforge.net/
COMMENT=		System for aligning whole genome sequences

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_TOOLS+=		gmake perl:run
USE_LANGUAGES=		c c++

MAKE_ENV+=		SH=${SH:Q}
MAKE_ENV+=		PERL=${PERL5:Q}
INSTALLATION_DIRS=	bin

do-install:
.for PROGRAM in annotate combineMUMs delta-filter gaps mgaps mummer \
	repeat-match show-aligns show-coords show-snps show-tiling
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor
.for PROGRAM in postnuc postpro prenuc prepro
	${INSTALL_PROGRAM} ${WRKSRC}/aux_bin/${PROGRAM} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/mummer
.for SCRIPT in run-mummer1 run-mummer3 nucmer promer exact-tandems 	  \
	mapview mummerplot nucmer2xfig
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${PREFIX}/share/mummer
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mummer
.for HTML in MUMmer.pdf MUMmer2.pdf MUMmer3.pdf XFiles.pdf \
	applications.html compare.html index.html logo.gif \
	mummer-help.gif mummer-users.gif
	${INSTALL_DATA} ${WRKSRC}/docs/web/${HTML}			\
		${PREFIX}/share/doc/html/mummer
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mummer/examples
.for HTML in dotplot.gif examples_logo.gif index.html mapplot.gif \
	mapview_fig.jpg mummer_ps.jpg
	${INSTALL_DATA} ${WRKSRC}/docs/web/examples/${HTML}		\
		${PREFIX}/share/doc/html/mummer/examples
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mummer/examples/data
.for DATA in B_anthracis_Mslice.fasta B_anthracis_contigs.fasta \
	D_melanogaster_2Rslice.cds D_melanogaster_2Rslice.fasta \
	D_melanogaster_2Rslice.utr D_pseudoobscura_contigs.fasta \
	H_pylori26695_Bslice.fasta H_pylori26695_Eslice.fasta \
	H_pyloriJ99_Bslice.fasta H_pyloriJ99_Eslice.fasta README \
	mapview_0.fig mapview_0.pdf mummer.fplot mummer.gp mummer.mums \
	mummer.ps mummer.rplot mummer1.align mummer1.errorsgaps \
	mummer1.gaps mummer1.out mummer3.align mummer3.errorsgaps \
	mummer3.gaps mummer3.out nucmer.cluster nucmer.coords \
	nucmer.delta nucmer.snps nucmer.tiling promer.aligns \
	promer.cluster promer.coords promer.delta
	${INSTALL_DATA} ${WRKSRC}/docs/web/examples/data/${DATA} 	\
		${PREFIX}/share/doc/html/mummer/examples/data
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mummer/manual
.for HTML in covplot.gif dotplot.gif gaps.gif index.html 	  \
	manual_logo.gif mgaps.gif multiplota.gif multiplotb.gif \
	nuc_proex.gif nucex.gif osi.gif pro_proex.gif
	${INSTALL_DATA}	${WRKSRC}/docs/web/manual/${HTML} 		  \
		${PREFIX}/share/doc/html/mummer/manual
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mummer
.for DOC in mapview.README maxmat3man.tex maxmat3src.pdf nucmer.README    \
	optionman.sty promer.README run-mummer1.README run-mummer3.README \
	skaff.sty
	${INSTALL_DATA} ${WRKSRC}/docs/${DOC} ${PREFIX}/share/doc/mummer
.endfor

.include "../../mk/bsd.pkg.mk"
