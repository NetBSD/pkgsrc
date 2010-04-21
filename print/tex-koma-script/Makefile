# $NetBSD: Makefile,v 1.2 2010/04/21 05:58:05 minskim Exp $
# TeX Live Revision 17067

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.05

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of versatile classes and packages

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
