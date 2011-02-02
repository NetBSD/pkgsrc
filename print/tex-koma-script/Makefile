# $NetBSD: Makefile,v 1.5 2011/02/02 18:13:18 minskim Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.08
TEXLIVE_REV=	21195

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of versatile classes and packages

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
