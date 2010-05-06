# $NetBSD: Makefile,v 1.3 2010/05/06 15:15:41 reed Exp $
# TeX Live Revision 16172

DISTNAME=	latex
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX macro package that defines LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-latexconfig>=2009:../../print/tex-latexconfig
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
DEPENDS+=	tex-luatex-[0-9]*:../../print/tex-luatex
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
