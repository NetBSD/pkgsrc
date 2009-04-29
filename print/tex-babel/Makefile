# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 20:57:59 minskim Exp $
# TeX Live Revision 9808

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.8l

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Multilingual support for Plain TeX or LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
