# $NetBSD: Makefile,v 1.10 2021/02/26 06:21:04 mef Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0e
TEXLIVE_REV=	53545

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/colortbl
COMMENT=	Add colour to LaTeX tables
LICENSE=	lppl-1.3c

#EPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
