# $NetBSD: Makefile,v 1.22 2024/02/15 19:24:14 markd Exp $

DISTNAME=	pdfpages
PKGNAME=	tex-${DISTNAME}-0.5y
TEXLIVE_REV=	69524

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdfpages
COMMENT=	Include PDF documents in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-eso-pic-[0-9]*:../../print/tex-eso-pic
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-pdflscape-[0-9]*:../../print/tex-pdflscape
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
