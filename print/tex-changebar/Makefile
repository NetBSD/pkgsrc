# $NetBSD: Makefile,v 1.9 2024/11/12 22:52:04 markd Exp $

DISTNAME=	changebar
PKGNAME=	tex-${DISTNAME}-3.7e
TEXLIVE_REV=	71847

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/changebar
COMMENT=	Generate changebars in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
