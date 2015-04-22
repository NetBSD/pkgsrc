# $NetBSD: Makefile,v 1.7 2015/04/22 09:35:02 markd Exp $

DISTNAME=	amscls
PKGNAME=	tex-${DISTNAME}-2014.34870
TEXLIVE_REV=	34870

MAINTAINER=	minskim@NetBSD.org
COMMENT=	AMS document classes for LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
