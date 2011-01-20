# $NetBSD: Makefile,v 1.3 2011/01/20 16:23:59 minskim Exp $

DISTNAME=	pgfplots
PKGNAME=	tex-${DISTNAME}-1.4.1
TEXLIVE_REV=	19839

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX package to create normal/logarithmic plots

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
