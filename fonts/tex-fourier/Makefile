# $NetBSD: Makefile,v 1.1.1.1 2011/03/13 23:30:47 minskim Exp $

DISTNAME=	fourier
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Using Utopia fonts in LaTeX documents

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEX_MAP_FILES+=	fourier.map
TEX_MAP_FILES+=	fourier-utopia-expert.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
