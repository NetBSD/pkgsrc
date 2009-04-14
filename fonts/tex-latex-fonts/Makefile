# $NetBSD: Makefile,v 1.1.1.1 2009/04/14 18:01:55 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	latex-fonts
PKGNAME=	tex-${DISTNAME}-2008.7340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Collection of fonts used in LaTeX distributions

CONFLICTS+=	teTeX-texmf<=3.0nb12

TEX_MIXEDMAP_FILES+=	latex-bsr.map

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
