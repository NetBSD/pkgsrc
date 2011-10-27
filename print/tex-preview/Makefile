# $NetBSD: Makefile,v 1.1.1.1 2011/10/27 17:14:37 minskim Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-11.86
TEXLIVE_REV=	17118

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extract bits of a LaTeX source for output

CONFLICTS=	teTeX-texmf<3.0nb32
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
