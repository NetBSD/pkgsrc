# $NetBSD: Makefile,v 1.2 2010/02/19 18:19:45 minskim Exp $
# TeX Live Revision 12705

DISTNAME=	oberdiek
PKGNAME=	tex-${DISTNAME}-2008.12705
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of packages submitted by Heiko Oberdiek

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
