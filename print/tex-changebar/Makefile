# $NetBSD: Makefile,v 1.4 2018/05/06 01:30:20 markd Exp $

DISTNAME=	changebar
PKGNAME=	tex-${DISTNAME}-3.6c
TEXLIVE_REV=	46919

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/changebar
COMMENT=	Generate changebars in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
