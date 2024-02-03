# $NetBSD: Makefile,v 1.8 2024/02/03 04:04:52 markd Exp $

DISTNAME=	changebar
PKGNAME=	tex-${DISTNAME}-3.7d
TEXLIVE_REV=	69367

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/changebar
COMMENT=	Generate changebars in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
