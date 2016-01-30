# $NetBSD: Makefile,v 1.2 2016/01/30 03:26:10 markd Exp $

DISTNAME=	changebar
PKGNAME=	tex-${DISTNAME}-3.5c
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Generate changebars in LaTeX documents
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb28
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
