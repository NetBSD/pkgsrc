# $NetBSD: Makefile,v 1.12 2011/10/18 20:30:59 minskim Exp $

DISTNAME=	ucs
PKGNAME=	tex-${DISTNAME}-20041710
PKGREVISION=	5
TEXLIVE_REV=	17090

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extended UTF-8 input encoding for LaTeX

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
