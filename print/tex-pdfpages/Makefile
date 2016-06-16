# $NetBSD: Makefile,v 1.6 2016/06/16 04:06:14 markd Exp $

DISTNAME=	pdfpages
PKGNAME=	tex-${DISTNAME}-0.5f
TEXLIVE_REV=	40638

MAINTAINER=	minskim@NetBSD.org
HOMEPAPE=	http://ctan.org/pkg/pdfpages
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
