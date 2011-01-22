# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 22:00:48 minskim Exp $

DISTNAME=	euler
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	17261

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Use AMS Euler fonts for math

CONFLICTS+=	teTeX-texmf<3.0nb29
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
