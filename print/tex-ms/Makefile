# $NetBSD: Makefile,v 1.1.1.1 2009/07/10 00:15:02 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	ms
PKGNAME=	tex-${DISTNAME}-2008.7340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Various LaTeX packages by Martin Schroeder

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
