# $NetBSD: Makefile,v 1.4 2015/04/08 05:43:48 wiz Exp $

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
