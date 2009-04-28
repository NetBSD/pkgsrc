# $NetBSD: Makefile,v 1.1.1.1 2009/04/28 18:30:42 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	amsfonts
PKGNAME=	tex-${DISTNAME}-2.2

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX fonts from the American Mathematical Society

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-ams-[0-9]*:../../print/tex-ams
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
