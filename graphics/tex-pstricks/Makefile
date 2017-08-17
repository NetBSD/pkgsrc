# $NetBSD: Makefile,v 1.9 2017/08/17 01:33:43 markd Exp $

DISTNAME=	pstricks
PKGNAME=	tex-${DISTNAME}-2.74
TEXLIVE_REV=	44617

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pstricks-base
COMMENT=	PostScript macros for TeX
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb29
DEPENDS+=	tex-auto-pst-pdf-[0-9]*:../../graphics/tex-auto-pst-pdf
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
