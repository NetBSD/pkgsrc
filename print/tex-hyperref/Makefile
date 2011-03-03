# $NetBSD: Makefile,v 1.11 2011/03/03 22:24:02 minskim Exp $

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-6.82a
TEXLIVE_REV=	21339

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extensive support for hypertext in LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
