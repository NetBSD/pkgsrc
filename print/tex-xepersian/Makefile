# $NetBSD: Makefile,v 1.3 2024/02/17 04:22:36 markd Exp $

DISTNAME=	xepersian
PKGNAME=	tex-${DISTNAME}-25.0
TEXLIVE_REV=	68117

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xepersian
COMMENT=	Persian for LaTeX, using XeTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-bidi-[0-9]*:../../print/tex-bidi
DEPENDS+=	tex-datetime-[0-9]*:../../print/tex-datetime
DEPENDS+=	tex-fancybox-[0-9]*:../../print/tex-fancybox
DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-hyphenat-[0-9]*:../../print/tex-hyphenat
# ifxetex
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-lastpage-[0-9]*:../../print/tex-lastpage
# ifthen
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
# fullpage
DEPENDS+=	tex-preprint-[0-9]*:../../print/tex-preprint
# pifont
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-ragged2e-[0-9]*:../../print/tex-ragged2e
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-textpos-[0-9]*:../../print/tex-textpos
# calc, multicol, tabularx, verbatim
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
