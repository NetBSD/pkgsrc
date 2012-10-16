# $NetBSD: Makefile,v 1.5 2012/10/16 21:41:00 minskim Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2012
TEXLIVE_REV=	26263

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The LaTeX standard tools bundle

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
