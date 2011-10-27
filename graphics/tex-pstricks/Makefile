# $NetBSD: Makefile,v 1.2 2011/10/27 18:01:54 minskim Exp $

DISTNAME=	pstricks
PKGNAME=	tex-${DISTNAME}-2.23
TEXLIVE_REV=	23858

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PostScript macros for TeX

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
