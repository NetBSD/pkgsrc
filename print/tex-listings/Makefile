# $NetBSD: Makefile,v 1.1.1.1 2009/08/03 23:45:46 minskim Exp $
# TeX Live Revision 8662

DISTNAME=	listings
PKGNAME=	tex-${DISTNAME}-1.4

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset source code listings using LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb20
DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
