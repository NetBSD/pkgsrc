# $NetBSD: Makefile,v 1.3 2010/11/15 17:54:13 minskim Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.8l
PKGREVISION=	2
TEXLIVE_REV=	20253

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Multilingual support for Plain TeX or LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
