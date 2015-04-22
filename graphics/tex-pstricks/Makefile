# $NetBSD: Makefile,v 1.4 2015/04/22 00:11:23 markd Exp $

DISTNAME=	pstricks
PKGNAME=	tex-${DISTNAME}-2.60
TEXLIVE_REV=	35439

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PostScript macros for TeX

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-auto-pst-pdf-[0-9]*:../../graphics/tex-auto-pst-pdf
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
