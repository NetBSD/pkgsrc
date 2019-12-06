# $NetBSD: Makefile,v 1.4 2019/12/06 19:30:01 markd Exp $

DISTNAME=	fourier
PKGNAME=	tex-${DISTNAME}-1.3
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Using Utopia fonts in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEX_MAP_FILES+=	fourier.map
TEX_MAP_FILES+=	fourier-utopia-expert.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
