# $NetBSD: Makefile,v 1.23 2025/05/10 23:58:51 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-20241102
TEXLIVE_REV=	72739

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
