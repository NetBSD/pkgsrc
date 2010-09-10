# $NetBSD: Makefile,v 1.4 2010/09/10 23:56:32 minskim Exp $

DISTNAME=	algorithm2e
PKGNAME=	tex-${DISTNAME}-4.01
TEXLIVE_REV=	16417

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Floating algorithm environment with algorithmic keywords

DEPENDS+=	tex-endfloat-[0-9]*:../../print/tex-endfloat
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-relsize-[0-9]*:../../print/tex-relsize
DEPENDS+=	tex-tocbibind-[0-9]*:../../print/tex-tocbibind
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
