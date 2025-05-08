# $NetBSD: Makefile,v 1.8 2025/05/08 11:36:04 markd Exp $

DISTNAME=	fourier
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	72243

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fourier
COMMENT=	Using Utopia fonts in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEX_MAP_FILES+=	fourier-utopia-expert.map
TEX_MAP_FILES+=	fourier.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
