# $NetBSD: Makefile,v 1.13 2024/02/25 18:39:58 markd Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0g
TEXLIVE_REV=	70034

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/colortbl
COMMENT=	Add colour to LaTeX tables
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
