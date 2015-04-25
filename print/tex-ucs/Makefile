# $NetBSD: Makefile,v 1.13 2015/04/25 05:20:08 markd Exp $

DISTNAME=	ucs
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	35853

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended UTF-8 input encoding for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
