# $NetBSD: Makefile,v 1.9 2017/08/17 03:58:16 markd Exp $

DISTNAME=	pdfpages
PKGNAME=	tex-${DISTNAME}-0.5j
TEXLIVE_REV=	44812

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pdfpages
COMMENT=	Include PDF documents in LaTeX
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
