# $NetBSD: Makefile,v 1.8 2010/09/27 15:45:35 minskim Exp $

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-6.81p
PKGREVISION=	2
TEXLIVE_REV=	19782

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extensive support for hypertext in LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-ltxmisc>=2010:../../print/tex-ltxmisc
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
