# $NetBSD: Makefile,v 1.5 2015/04/23 12:06:26 markd Exp $

DISTNAME=	listings
PKGNAME=	tex-${DISTNAME}-1.5e
TEXLIVE_REV=	35124

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Typeset source code listings using LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb20
DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
