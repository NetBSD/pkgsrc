# $NetBSD: Makefile,v 1.16 2020/05/05 12:01:05 markd Exp $

DISTNAME=	tools
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	53640

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-tools
COMMENT=	The LaTeX standard tools bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
