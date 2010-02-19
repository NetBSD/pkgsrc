# $NetBSD: Makefile,v 1.3 2010/02/19 18:19:45 minskim Exp $
# TeX Live Revision 12984

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-6.78r
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extensive support for hypertext in LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
