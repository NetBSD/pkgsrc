# $NetBSD: Makefile,v 1.10 2015/04/23 11:59:55 markd Exp $

DISTNAME=	latexconfig
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	34655

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files used to generate LaTeX formats

CONFLICTS+=	teTeX-texmf<=3.0nb12
CONFLICTS+=	tex-bin-latex<2008.12778nb5

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
