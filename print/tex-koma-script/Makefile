# $NetBSD: Makefile,v 1.7 2011/07/16 17:32:00 minskim Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.09
TEXLIVE_REV=	21983

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of versatile classes and packages

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
