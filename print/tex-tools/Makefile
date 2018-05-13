# $NetBSD: Makefile,v 1.12 2018/05/13 11:14:09 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47500

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
