# $NetBSD: Makefile,v 1.11 2017/10/16 09:15:10 markd Exp $

DISTNAME=	pdfpages
PKGNAME=	tex-${DISTNAME}-0.5k
TEXLIVE_REV=	45043

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pdfpages
COMMENT=	Include PDF documents in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
