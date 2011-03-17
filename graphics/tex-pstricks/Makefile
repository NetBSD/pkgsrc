# $NetBSD: Makefile,v 1.1.1.1 2011/03/17 18:12:47 minskim Exp $

DISTNAME=	pstricks
PKGNAME=	tex-${DISTNAME}-2.17
TEXLIVE_REV=	21291

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PostScript macros for TeX

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
