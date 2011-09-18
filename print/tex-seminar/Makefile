# $NetBSD: Makefile,v 1.1.1.1 2011/09/18 00:41:30 minskim Exp $

DISTNAME=	seminar
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	18322

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Make overhead slides

CONFLICTS+=	teTeX-texmf<=3.0nb30
DEPENDS+=	tex-2up-[0-9]*:../../print/tex-2up
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xcomment-[0-9]*:../../print/tex-xcomment

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
