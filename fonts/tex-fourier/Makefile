# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:45 markd Exp $

DISTNAME=	fourier
PKGNAME=	tex-${DISTNAME}-2.2
PKGREVISION=	1
TEXLIVE_REV=	54090

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fourier
COMMENT=	Using Utopia fonts in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEX_MAP_FILES+=	fourier.map
TEX_MAP_FILES+=	fourier-utopia-expert.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
