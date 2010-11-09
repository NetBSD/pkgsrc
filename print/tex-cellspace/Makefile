# $NetBSD: Makefile,v 1.1.1.1 2010/11/09 16:28:44 minskim Exp $

DISTNAME=	cellspace
PKGNAME=	tex-${DISTNAME}-1.6
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Ensure minimal spacing of table cells

DEPENDS+=	tex-amsmath>=2.13nb1:../../print/tex-amsmath
DEPENDS+=	tex-latex>=2009:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-tools>=2010:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
