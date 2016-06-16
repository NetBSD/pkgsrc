# $NetBSD: Makefile,v 1.7 2016/06/16 04:06:11 markd Exp $

DISTNAME=	latex-bin
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40963

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX executables

CONFLICTS+=	teTeX-texmf<=3.0nb21
CONFLICTS+=	tex-bin-latex<2009
DEPENDS+=	tex-latex>=2012:../../print/tex-latex
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
SUPERSEDES=	tex-bin-latex<2009

INSTALLATION_DIRS=	bin

TEX_FORMATS+=	"latex pdftex language.dat -translate-file=cp227.tcx *latex.ini\\npdflatex pdftex language.dat -translate-file=cp227.tcx *pdflatex.ini\\ndvilualatex luatex language.dat,language.dat.lua dvilualatex.ini\\nlualatex luatex language.dat,language.dat.lua lualatex.ini\\n"
TEX_TEXMF_DIRS=	# empty

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/latex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdflatex
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/dvilualatex
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/lualatex

.include "../../mk/bsd.pkg.mk"
