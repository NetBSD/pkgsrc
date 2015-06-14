# $NetBSD: Makefile,v 1.3 2015/06/14 12:50:02 markd Exp $

DISTNAME=	fmtcount
PKGNAME=	tex-${DISTNAME}-3.01
TEXLIVE_REV=	37298

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Display the value of a LaTeX counter in a variety of formats
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath>=2.13:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
