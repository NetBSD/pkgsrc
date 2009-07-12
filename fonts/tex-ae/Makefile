# $NetBSD: Makefile,v 1.1.1.1 2009/07/12 02:34:33 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	ae
PKGNAME=	tex-${DISTNAME}-1.4

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Virtual fonts for T1 encoded CMR-fonts

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
