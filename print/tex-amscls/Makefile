# $NetBSD: Makefile,v 1.8 2015/06/14 12:50:01 markd Exp $

DISTNAME=	amscls
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	36804

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/amscls
COMMENT=	AMS document classes for LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
