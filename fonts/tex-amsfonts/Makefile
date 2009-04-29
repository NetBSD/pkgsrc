# $NetBSD: Makefile,v 1.2 2009/04/29 04:24:33 minskim Exp $
# TeX Live Revision 7340

DISTNAME=	amsfonts
PKGNAME=	tex-${DISTNAME}-2.2
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX fonts from the American Mathematical Society

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-ams-[0-9]*:../../print/tex-ams
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-cmex-[0-9]*:../../fonts/tex-cmex

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
