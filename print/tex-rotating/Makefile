# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 18:27:58 minskim Exp $
# TeX Live Revision 12557

DISTNAME=	rotating
PKGNAME=	tex-${DISTNAME}-2.16a

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Rotation tools including rotated full-page floats

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
