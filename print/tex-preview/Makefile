# $NetBSD: Makefile,v 1.2 2015/04/25 04:23:29 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-11.88
TEXLIVE_REV=	35488

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Extract bits of a LaTeX source for output

CONFLICTS=	teTeX-texmf<3.0nb32
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
