# $NetBSD: Makefile,v 1.7 2017/08/17 03:14:22 markd Exp $

DISTNAME=	fancyhdr
PKGNAME=	tex-${DISTNAME}-3.9a
TEXLIVE_REV=	44730

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fancyhdr
COMMENT=	Extensive control of page headers and footers in LaTeX2e
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
