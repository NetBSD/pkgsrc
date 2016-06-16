# $NetBSD: Makefile,v 1.12 2016/06/16 04:06:11 markd Exp $

DISTNAME=	latexconfig
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40274

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files used to generate LaTeX formats

CONFLICTS+=	teTeX-texmf<=3.0nb12
CONFLICTS+=	tex-bin-latex<2008.12778nb5

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
