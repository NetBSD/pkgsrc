# $NetBSD: Makefile,v 1.1.1.1 2011/09/17 22:51:05 minskim Exp $

DISTNAME=	statex
PKGNAME=	tex-${DISTNAME}-1.6
TEXLIVE_REV=	20306

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Statistics style

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
