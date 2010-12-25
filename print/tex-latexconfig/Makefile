# $NetBSD: Makefile,v 1.5 2010/12/25 02:30:12 minskim Exp $

DISTNAME=	latexconfig
PKGNAME=	tex-${DISTNAME}-2010.${TEXLIVE_REV}
TEXLIVE_REV=	20663

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files used to generate LaTeX formats

CONFLICTS+=	teTeX-texmf<=3.0nb12
CONFLICTS+=	tex-bin-latex<2008.12778nb5

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
