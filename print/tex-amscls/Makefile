# $NetBSD: Makefile,v 1.3 2010/05/02 16:47:23 minskim Exp $
# TeX Live Revision 15878

DISTNAME=	amscls
PKGNAME=	tex-${DISTNAME}-2009

MAINTAINER=	minskim@NetBSD.org
COMMENT=	AMS document classes for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
