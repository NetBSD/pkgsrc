# $NetBSD: Makefile,v 1.7 2017/08/17 03:05:36 markd Exp $

DISTNAME=	babel
PKGNAME=	tex-${DISTNAME}-3.12
TEXLIVE_REV=	44722

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/babel
COMMENT=	Multilingual support for Plain TeX or LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-latex>=2009:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
