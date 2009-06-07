# $NetBSD: Makefile,v 1.1.1.1 2009/06/07 06:56:38 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	manfnt
PKGNAME=	tex-${DISTNAME}-2008.7340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support for the TeX book symbols

CONFLICTS+=	teTeX-texmf<=3.0nb15
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex

TEX_MIXEDMAP_FILES+=	manfnt.map

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
