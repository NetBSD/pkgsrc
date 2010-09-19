# $NetBSD: Makefile,v 1.3 2010/09/19 23:20:33 minskim Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	19766

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The LaTeX standard tools bundle

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
