# $NetBSD: Makefile,v 1.5 2016/06/16 04:05:59 markd Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.9r
TEXLIVE_REV=	40706

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
