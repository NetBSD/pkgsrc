# $NetBSD: Makefile,v 1.3 2017/09/06 16:49:31 wiz Exp $

DISTNAME=	changebar
PKGNAME=	tex-${DISTNAME}-3.5c
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Generate changebars in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
