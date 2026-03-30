# $NetBSD: Makefile,v 1.17 2026/03/30 07:48:26 markd Exp $

DISTNAME=	listings
PKGNAME=	tex-${DISTNAME}-1.11b
TEXLIVE_REV=	77682

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/listings
COMMENT=	Typeset source code listings using LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-algorithms-[0-9]*:../../print/tex-algorithms
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
