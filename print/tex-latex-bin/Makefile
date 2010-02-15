# $NetBSD: Makefile,v 1.1.1.1 2010/02/15 20:29:15 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	latex-bin
PKGNAME=	tex-${DISTNAME}-2009

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX executables

CONFLICTS+=	teTeX-texmf<=3.0nb31
CONFLICTS+=	tex-bin-latex<2009
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
SUPERSEDES=	tex-bin-latex<2009

INSTALLATION_DIRS=	bin

TEX_FORMATS+=	"latex pdftex language.dat -translate-file=cp227.tcx *latex.ini\\npdflatex pdftex language.dat -translate-file=cp227.tcx *pdflatex.ini\\ndvilualatex luatex language.dat dvilualatex.ini\\nlualatex luatex language.dat lualatex.ini\\n"
TEX_TEXMF_DIRS=	# empty

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/latex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdflatex
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/dvilualatex
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/lualatex

.include "../../mk/bsd.pkg.mk"
