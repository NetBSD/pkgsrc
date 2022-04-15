# $NetBSD: Makefile,v 1.18 2022/04/15 04:53:13 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	61041

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
