# $NetBSD: Makefile,v 1.1.1.1 2009/07/16 23:25:23 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	algorithms
PKGNAME=	tex-${DISTNAME}-2008.7340

MAINTAINER=	minskim@NetBSD.org
COMMENT=	A suite of tools for typesetting algorithms in pseudo-code
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	teTeX-texmf<=3.0nb19
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
