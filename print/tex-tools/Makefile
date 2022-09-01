# $NetBSD: Makefile,v 1.19 2022/09/01 05:43:30 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2022
TEXLIVE_REV=	63514

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
