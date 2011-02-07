# $NetBSD: Makefile,v 1.1.1.1 2011/02/07 00:19:55 minskim Exp $

DISTNAME=	tocloft
PKGNAME=	tex-${DISTNAME}-2.3e
TEXLIVE_REV=	20084

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control table of contents, figures, etc. for LaTeX

CONFLICTS=	teTeX-texmf<=3.0nb9
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
