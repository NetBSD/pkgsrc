# $NetBSD: Makefile,v 1.4 2010/09/19 14:14:29 minskim Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.07
TEXLIVE_REV=	19797

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of versatile classes and packages

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
