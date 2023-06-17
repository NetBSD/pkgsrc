# $NetBSD: Makefile,v 1.21 2023/06/17 10:47:58 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	67314

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
