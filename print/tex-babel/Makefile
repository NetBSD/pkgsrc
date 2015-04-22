# $NetBSD: Makefile,v 1.4 2015/04/22 10:02:03 markd Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.9l
TEXLIVE_REV=	35266

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Multilingual support for Plain TeX or LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
