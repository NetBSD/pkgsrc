# $NetBSD: Makefile,v 1.11 2015/06/14 12:50:04 markd Exp $

DISTNAME=	latexconfig
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	37197

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files used to generate LaTeX formats

CONFLICTS+=	teTeX-texmf<=3.0nb12
CONFLICTS+=	tex-bin-latex<2008.12778nb5

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
