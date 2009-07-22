# $NetBSD: Makefile,v 1.1.1.1 2009/07/22 07:01:38 minskim Exp $
# TeX Live Revision 10740

DISTNAME=	elsarticle
PKGNAME=	tex-${DISTNAME}-1.0.1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Class for articles for submission to Elsevier journals

DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times
DEPENDS+=	tex-txfonts-[0-9]*:../../fonts/tex-txfonts

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
