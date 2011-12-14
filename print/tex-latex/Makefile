# $NetBSD: Makefile,v 1.6 2011/12/14 20:14:25 minskim Exp $

DISTNAME=	latex
PKGNAME=	tex-${DISTNAME}-2011
TEXLIVE_REV=	23639

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX macro package that defines LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-latexconfig>=2011:../../print/tex-latexconfig
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
