# $NetBSD: Makefile,v 1.2 2009/07/12 02:54:43 minskim Exp $
# TeX Live Revision 12163

DISTNAME=	amscls
PKGNAME=	tex-${DISTNAME}-2008.12163
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	AMS document classes for LaTeX

CONFLICTS+=	teTeX-texmf<=3.0nb18
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
