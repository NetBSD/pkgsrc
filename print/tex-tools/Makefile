# $NetBSD: Makefile,v 1.17 2021/02/13 05:41:37 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2020.56514
TEXLIVE_REV=	56514

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
