# $NetBSD: Makefile,v 1.5 2010/09/29 22:17:59 minskim Exp $

DISTNAME=	oberdiek
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	2
TEXLIVE_REV=	18100

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Bundle of packages submitted by Heiko Oberdiek

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
