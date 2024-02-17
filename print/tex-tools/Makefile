# $NetBSD: Makefile,v 1.22 2024/02/17 01:37:23 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-20231101c
TEXLIVE_REV=	68941

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
