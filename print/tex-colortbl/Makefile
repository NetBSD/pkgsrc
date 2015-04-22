# $NetBSD: Makefile,v 1.5 2015/04/22 10:29:38 markd Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0a
TEXLIVE_REV=	29803

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Add colour to LaTeX tables

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
