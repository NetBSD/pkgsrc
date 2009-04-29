# $NetBSD: Makefile,v 1.1.1.1 2009/04/29 03:03:03 minskim Exp $
# TeX Live Revision 12705

DISTNAME=	oberdiek
PKGNAME=	tex-${DISTNAME}-2008.12705

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of packages submitted by Heiko Oberdiek

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
