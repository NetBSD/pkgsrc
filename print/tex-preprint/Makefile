# $NetBSD: Makefile,v 1.1.1.1 2009/07/07 23:15:04 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	preprint
PKGNAME=	tex-${DISTNAME}-2008.7340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of LaTeX packages provided as-is

CONFLICTS+=	teTeX-texmf<=3.0nb16
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
