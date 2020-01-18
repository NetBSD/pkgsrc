# $NetBSD: Makefile,v 1.15 2020/01/18 23:34:58 rillig Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2018.49619
TEXLIVE_REV=	49619

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
