# $NetBSD: Makefile,v 1.5 2012/10/16 21:52:51 minskim Exp $

DISTNAME=	amsmath
PKGNAME=	tex-${DISTNAME}-2.13
PKGREVISION=	2
TEXLIVE_REV=	26389

MAINTAINER=	minskim@NetBSD.org
COMMENT=	AMS mathematical facilities for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
