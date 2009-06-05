# $NetBSD: Makefile,v 1.5 2009/06/05 21:38:32 minskim Exp $
# TeX Live Revision 12778

DISTNAME=	bin-latex
PKGNAME=	tex-${DISTNAME}-2008.12778
PKGREVISION=	3
DIST_SUBDIR=	${PKGNAME_NOREV}nb1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX macro package that defines LaTeX

CONFLICTS+=	teTeX-bin<=3.0nb31
DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-bin-kpathsea-[0-9]*:../../print/tex-bin-kpathsea
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latexconfig-[0-9]*:../../print/tex-latexconfig
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

INSTALLATION_DIRS+=	bin

TEX_FORMAT_NAMES+=	latex
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/module.mk"

post-install:
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/latex
	${LN} -sf pdftex ${DESTDIR}${PREFIX}/bin/pdflatex
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/lualatex
	${LN} -sf luatex ${DESTDIR}${PREFIX}/bin/pdflualatex

.include "../../mk/bsd.pkg.mk"
