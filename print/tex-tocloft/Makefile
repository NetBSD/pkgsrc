# $NetBSD: Makefile,v 1.2 2015/04/25 05:11:25 markd Exp $

DISTNAME=	tocloft
PKGNAME=	tex-${DISTNAME}-2.3f
TEXLIVE_REV=	30209

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control table of contents, figures, etc. for LaTeX
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<=3.0nb9
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
