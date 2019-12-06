# $NetBSD: Makefile,v 1.14 2019/12/06 20:23:33 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2018.49619
TEXLIVE_REV=	49619

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
