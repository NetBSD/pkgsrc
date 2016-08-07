# $NetBSD: Makefile,v 1.14 2016/08/07 09:09:38 markd Exp $

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-6.83q
TEXLIVE_REV=	41539

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extensive support for hypertext in LaTeX
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek
DEPENDS+=	tex-url>=3.2:../../print/tex-url

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
