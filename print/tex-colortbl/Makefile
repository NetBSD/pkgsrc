# $NetBSD: Makefile,v 1.7 2019/01/28 11:41:16 markd Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0d
TEXLIVE_REV=	49404

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Add colour to LaTeX tables
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
