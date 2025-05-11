# $NetBSD: Makefile,v 1.18 2025/05/11 03:50:57 markd Exp $

DISTNAME=	latex-bin
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	73848

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX executables

CONFLICTS+=	tex-bin-latex<2009
DEPENDS+=	tex-babel>3.14:../../print/tex-babel
DEPENDS+=	tex-dehyph-[0-9]*:../../print/tex-dehyph
DEPENDS+=	tex-firstaid-[0-9]*:../../print/tex-firstaid
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
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
