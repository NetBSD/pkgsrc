# $NetBSD: Makefile,v 1.5 2015/04/25 03:56:15 markd Exp $

DISTNAME=	pgfplots
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	36178

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX package to create normal/logarithmic plots

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
