# $NetBSD: Makefile,v 1.1.1.1 2009/04/28 01:17:12 minskim Exp $
# TeX Live Revision 7983

DISTNAME=	amsmath
PKGNAME=	tex-${DISTNAME}-2.13

MAINTAINER=	minskim@NetBSD.org
COMMENT=	AMS mathematical facilities for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-ams-[0-9]*:../../print/tex-ams

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
