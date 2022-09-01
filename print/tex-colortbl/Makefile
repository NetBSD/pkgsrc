# $NetBSD: Makefile,v 1.12 2022/09/01 03:39:21 markd Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0f
TEXLIVE_REV=	64015

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/colortbl
COMMENT=	Add colour to LaTeX tables
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
