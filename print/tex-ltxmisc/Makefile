# $NetBSD: Makefile,v 1.3 2010/02/19 18:19:45 minskim Exp $
# TeX Live Revision 12680

DISTNAME=	ltxmisc
PKGNAME=	tex-${DISTNAME}-2008.12680
PKGREVISION=	2

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Miscellaneous LaTeX packages

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-courier-[0-9]*:../../fonts/tex-courier
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
