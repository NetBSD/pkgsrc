# $NetBSD: Makefile,v 1.2 2010/02/19 18:19:45 minskim Exp $
# TeX Live Revision 12557

DISTNAME=	rotating
PKGNAME=	tex-${DISTNAME}-2.16a
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Rotation tools including rotated full-page floats

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
