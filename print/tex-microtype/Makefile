# $NetBSD: Makefile,v 1.1.1.1 2009/07/09 23:04:33 minskim Exp $
# TeX Live Revision 12566

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.3c

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Interface to the micro-typographic features of pdfTeX

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
