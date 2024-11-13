# $NetBSD: Makefile,v 1.14 2024/11/13 01:30:10 markd Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0i
TEXLIVE_REV=	71883

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/colortbl
COMMENT=	Add colour to LaTeX tables
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
