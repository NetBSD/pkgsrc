# $NetBSD: Makefile,v 1.2 2026/03/26 19:24:39 markd Exp $

DISTNAME=	tkz-grapheur
PKGNAME=	tex-${DISTNAME}-0.30d
TEXLIVE_REV=	78455

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tkz-grapheur
COMMENT=	LaTeX package with tools for graph plotting (and TikZ)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-pgfplots-[0-9]*:../../print/tex-pgfplots
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-simplekv-[0-9]*:../../print/tex-simplekv
DEPENDS+=	tex-siunitx-[0-9]*:../../print/tex-siunitx
DEPENDS+=	tex-xint-[0-9]*:../../math/tex-xint
DEPENDS+=	tex-xint-regression-[0-9]*:../../math/tex-xint-regression
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
