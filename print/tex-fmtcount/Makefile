# $NetBSD: Makefile,v 1.1.1.1 2011/01/12 16:30:54 minskim Exp $

DISTNAME=	fmtcount
PKGNAME=	tex-${DISTNAME}-1.31
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Display the value of a LaTeX counter in a variety of formats

DEPENDS+=	tex-amsmath>=2.13:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
