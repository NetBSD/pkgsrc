# $NetBSD: Makefile,v 1.8 2016/06/16 04:05:59 markd Exp $

DISTNAME=	amsmath
PKGNAME=	tex-${DISTNAME}-2.15b
TEXLIVE_REV=	40218

MAINTAINER=	minskim@NetBSD.org
COMMENT=	AMS mathematical facilities for LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
