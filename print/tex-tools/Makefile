# $NetBSD: Makefile,v 1.1.1.1 2009/04/24 19:13:39 minskim Exp $
# TeX Live Revision 11806

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2008.11806

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The LaTeX standard tools bundle

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
