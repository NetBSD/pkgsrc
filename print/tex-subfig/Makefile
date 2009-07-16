# $NetBSD: Makefile,v 1.1.1.1 2009/07/16 23:28:20 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	subfig
PKGNAME=	tex-${DISTNAME}-1.3

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Figures broken into subfigures

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
