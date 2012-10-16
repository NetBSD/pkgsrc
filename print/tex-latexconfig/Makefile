# $NetBSD: Makefile,v 1.8 2012/10/16 19:49:43 minskim Exp $

DISTNAME=	latexconfig
PKGNAME=	tex-${DISTNAME}-2012
TEXLIVE_REV=	26375

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files used to generate LaTeX formats

CONFLICTS+=	teTeX-texmf<=3.0nb12
CONFLICTS+=	tex-bin-latex<2008.12778nb5

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
