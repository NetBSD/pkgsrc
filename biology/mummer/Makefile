# $NetBSD: Makefile,v 1.8 2005/06/19 01:13:23 kristerw Exp $
#

DISTNAME=		MUMmer3.15
PKGNAME=		mummer-3.15
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/MUMmer/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.tigr.org/software/mummer/
COMMENT=		System for aligning whole genome sequences

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_TOOLS+=		gmake

MAKE_ENV+=		SH="${SH}"
MAKE_ENV+=		PERL="${PERL5}"
INSTALLATION_DIRS=	bin

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
.for DOC in maxmat3man.tex maxmat3src.pdf nucmer.README    \
	optionman.sty promer.README run-mummer1.README run-mummer3.README \
	skaff.sty
	${INSTALL_DATA} ${WRKSRC}/docs/${DOC} ${PREFIX}/share/doc/mummer
.endfor

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
