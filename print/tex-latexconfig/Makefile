# $NetBSD: Makefile,v 1.6 2011/05/26 22:38:47 minskim Exp $

DISTNAME=	latexconfig
PKGNAME=	tex-${DISTNAME}-2010.${TEXLIVE_REV}
TEXLIVE_REV=	21697

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files used to generate LaTeX formats

CONFLICTS+=	teTeX-texmf<=3.0nb12
CONFLICTS+=	tex-bin-latex<2008.12778nb5

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
