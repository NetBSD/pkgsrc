# $NetBSD: Makefile,v 1.15 2026/03/29 02:53:34 markd Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0k
TEXLIVE_REV=	77682

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/colortbl
COMMENT=	Add colour to LaTeX tables
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
