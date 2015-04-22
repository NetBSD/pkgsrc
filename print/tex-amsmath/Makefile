# $NetBSD: Makefile,v 1.6 2015/04/22 09:41:17 markd Exp $

DISTNAME=	amsmath
PKGNAME=	tex-${DISTNAME}-2.14
TEXLIVE_REV=	30645

MAINTAINER=	minskim@NetBSD.org
COMMENT=	AMS mathematical facilities for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
