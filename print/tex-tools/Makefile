# $NetBSD: Makefile,v 1.10 2017/06/21 13:25:34 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2017
TEXLIVE_REV=	43813

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
