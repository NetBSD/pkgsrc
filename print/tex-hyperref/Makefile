# $NetBSD: Makefile,v 1.5 2010/05/19 23:38:53 minskim Exp $

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-6.81a
TEXLIVE_REV=	18114

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extensive support for hypertext in LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
