# $NetBSD: Makefile,v 1.1.1.1 2009/04/23 22:33:55 minskim Exp $
# TeX Live Revision 8744

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.0o

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Standard LaTeX graphics

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
