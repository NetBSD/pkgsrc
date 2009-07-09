# $NetBSD: Makefile,v 1.1.1.1 2009/07/09 22:58:55 minskim Exp $
# TeX Live Revision 12679

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.03a

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of versatile classes and packages

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
