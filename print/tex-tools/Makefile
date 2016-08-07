# $NetBSD: Makefile,v 1.9 2016/08/07 09:09:41 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2016.41688
TEXLIVE_REV=	41688

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
