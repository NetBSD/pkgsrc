# $NetBSD: Makefile,v 1.9 2016/08/07 09:09:37 markd Exp $

DISTNAME=	amsmath
PKGNAME=	tex-${DISTNAME}-2.15d
TEXLIVE_REV=	41561

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-amsmath
COMMENT=	AMS mathematical facilities for LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
