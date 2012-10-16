# $NetBSD: Makefile,v 1.3 2012/10/16 22:24:17 minskim Exp $

DISTNAME=	pstricks
PKGNAME=	tex-${DISTNAME}-2.33
TEXLIVE_REV=	27795

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PostScript macros for TeX

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-auto-pst-pdf-[0-9]*:../../graphics/tex-auto-pst-pdf
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
