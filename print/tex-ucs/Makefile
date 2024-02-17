# $NetBSD: Makefile,v 1.16 2024/02/17 01:40:11 markd Exp $

DISTNAME=	ucs
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	68759

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ucs
COMMENT=	Extended UTF-8 input encoding support for LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
