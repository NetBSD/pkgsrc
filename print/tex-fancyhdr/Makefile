# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 05:49:05 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	fancyhdr
PKGNAME=	tex-${DISTNAME}-3.1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extensive control of page headers and footers in LaTeX2e

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
