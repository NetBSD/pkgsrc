# $NetBSD: Makefile,v 1.1.1.1 2009/04/14 18:16:52 minskim Exp $
# TeX Live Revision 11896

DISTNAME=	latex
PKGNAME=	tex-${DISTNAME}-2008.11896

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX macro package that defines LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
