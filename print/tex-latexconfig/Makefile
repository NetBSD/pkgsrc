# $NetBSD: Makefile,v 1.9 2013/11/17 18:27:25 minskim Exp $

DISTNAME=	latexconfig
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	28991

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files used to generate LaTeX formats

CONFLICTS+=	teTeX-texmf<=3.0nb12
CONFLICTS+=	tex-bin-latex<2008.12778nb5

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
