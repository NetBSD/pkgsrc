# $NetBSD: Makefile,v 1.1.1.1 2003/09/27 22:24:56 jschauma Exp $
#

DISTNAME=		MUMmer3.04
PKGNAME=		mummer-3.04
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/MUMmer/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.tigr.org/software/mummer/
COMMENT=		System for aligning whole genome sequences

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make

MAKE_ENV+=		SH="${SH}"

do-install:
.for PROGRAM in annotate combineMUMs gaps mgaps mummer repeat-match 	  \
	show-aligns show-coords show-tiling
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor
.for PROGRAM in postnuc postpro prenuc prepro
	${INSTALL_PROGRAM} ${WRKSRC}/aux_bin/${PROGRAM} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/mummer
.for SCRIPT in run-mummer1 run-mummer3 nucmer promer exact-tandems 	  \
	mummerplot nucmer2xfig
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${PREFIX}/share/mummer
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mummer
.for HTML in covplot.gif dotplot.gif email.jpg gaps.gif index.html 	  \
	manual_logo.gif mgaps.gif nuc_proex.gif nucex.gif osi.gif 	  \
	pro_proex.gif
	${INSTALL_DATA}	${WRKSRC}/docs/htmlmanual/${HTML} 		  \
		${PREFIX}/share/doc/html/mummer
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mummer
.for DOC in maxmat3man.pdf maxmat3man.tex maxmat3src.pdf nucmer.README    \
	optionman.sty promer.README run-mummer1.README run-mummer3.README \
	skaff.sty
	${INSTALL_DATA} ${WRKSRC}/docs/${DOC} ${PREFIX}/share/doc/mummer
.endfor

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
