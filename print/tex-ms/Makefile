# $NetBSD: Makefile,v 1.2 2010/05/12 01:23:47 minskim Exp $

DISTNAME=	ms
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	16596

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Various LaTeX packages by Martin Schroeder

CONFLICTS+=	teTeX-texmf<=3.0nb17
DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
