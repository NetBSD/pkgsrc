# $NetBSD: Makefile,v 1.6 2011/01/22 22:31:54 minskim Exp $

DISTNAME=	amscls
PKGNAME=	tex-${DISTNAME}-2010.20248
PKGREVISION=	1
TEXLIVE_REV=	20248

MAINTAINER=	minskim@NetBSD.org
COMMENT=	AMS document classes for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
