# $NetBSD: Makefile,v 1.2 2011/05/23 18:29:45 minskim Exp $

DISTNAME=	pdfpages
PKGNAME=	tex-${DISTNAME}-0.4n
TEXLIVE_REV=	21680

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Include PDF documents in LaTeX

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
